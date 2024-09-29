#include "mainwindow.h"
#include "./ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    iniciarLogo();
    frameMain();
    admin = new Usuario("admin", "admin", 0, "admin@gmail.com", "EDD2S2024");
    avl = new AVLtree();
    mensajeIS = new QMessageBox();
    feedGeneral = new DoublyLinkedList();
    usuariosGlobal = new ListaUsuarios();

    contenedor = new QWidget;
    layout = new QVBoxLayout(contenedor);
    bar = ui->scrollArea->verticalScrollBar();
    ui->scrollArea->setWidget(contenedor);
    contenedor->resize(ui->scrollArea->size());
    connect(bar, &QScrollBar::valueChanged, this, &MainWindow::actualizarFeed);
    connect(ui->editarPerfil, &QStackedWidget::currentChanged, this,&MainWindow::cargaEdicion);
}
void MainWindow::frameMain(){
    ui->ventanas->setCurrentIndex(0);
}

void MainWindow::cargaEdicion(){

    if (ventana){
        return;
    }

    QTableWidgetItem* interseccion = ui->adminUsuarios->item(ui->adminUsuarios->currentRow(),2);
    string user = interseccion->text().toStdString();


    editar = avl->buscarUsuario(user);
    if (!editar){
        return;
    }

    ui->editarNombre->setText(QString(editar->getNombre().c_str()));
    ui->editarApellido->setText(QString(editar->getApellido().c_str()));
    ui->editarCorreo->setText(QString(editar->getEmail().c_str()));
    ui->editarPass->setText(QString(editar->getPass().c_str()));
    QDateTime fecha;
    fecha.setSecsSinceEpoch(editar->getFechaNac());

    ui->editarFecha->setDateTime(fecha);
    ventana = true;
}

void MainWindow::iniciarLogo(){
    QFrame* inicio = ui->frameIS;
    logo = new QLabel(inicio);
    QPixmap pix("C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 2/Logo.png");
    logo->setPixmap(pix.scaled(200, 200, Qt::KeepAspectRatio));
    logo->setGeometry(this->width()/2-100, this->height()/8, 200, 100);
    logo->show();

}

void MainWindow::on_newUsuario_clicked()
{
    //creacion de Usuario
    string nombre = ui->newNombre->text().toStdString();
    string apellido = ui->newApellido->text().toStdString();
    string correo = ui->newCorreo->text().toStdString();
    QDateTime fecha = QDateTime(ui->newFecha->date(), QTime(0,0));
    time_t fechaNac = fecha.toSecsSinceEpoch();
    string pass = ui->newPass->text().toStdString();
    Usuario* userNew = new Usuario(nombre, apellido, fechaNac, correo, pass);
    Usuario* userFound = avl->buscarUsuario(correo);

    limpiarFormCC();

    if (userFound == nullptr){
        avl->insertar(userNew);
        ui->ventanas->setCurrentIndex(0);
    }else{
        mensajeIS->setText("Correo invalido");
        mensajeIS->show();
    }
}

void MainWindow::on_botonCC_clicked()
{
    limpiarForm();
    ui->ventanas->setCurrentIndex(3);
}

void MainWindow::on_back0_clicked()
{
    limpiarFormCC();
    ui->ventanas->setCurrentIndex(0);
}

void MainWindow::on_botonIS_clicked()
{
    string stdCorreo = ui->dataCorreo->text().toStdString();
    string stdPass = ui->dataPass->text().toStdString();

    if (stdCorreo == admin->getEmail() && stdPass == admin->getPass()){
        ui->ventanas->setCurrentIndex(1);
        ui->ordenAdmin->addItem(QString("Preorden"));
        ui->ordenAdmin->addItem(QString("Inorden"));
        ui->ordenAdmin->addItem(QString("PostOrden"));
        return;
    }

    perfil = avl->buscarUsuario(stdCorreo);

    if (perfil != nullptr){
        if (perfil->getPass() == stdPass){
            cargarPerfil();
            limpiarForm();
            cargarRecibidos();
            cargarSolicitudes();
            cargarTabla();
            ui->ventanas->setCurrentIndex(2);
            return ;
        }
    }

    mensajeIS->setText("Datos invalido");
    mensajeIS->show();
}

void MainWindow::cargarTabla(){
    avl->preOrdenTabla(avl->root,usuariosGlobal, perfil);
    bool bandera= true;
    QTableWidget* tableWidget = ui->tablaUsuarios;
    tableWidget->setRowCount(usuariosGlobal->contador);
    int row = 0;
    while(true){
        Usuario* acutal = usuariosGlobal->recorreraUno();
        if (acutal == nullptr){
            break;;
        }

        time_t fecha = acutal->getFechaNac();
        tm* fechaNac = localtime(&fecha);
        stringstream formatString;
        formatString << put_time(fechaNac, "%Y/%m/%d");
        tableWidget->setItem(row, 0, new QTableWidgetItem(QString(acutal->getNombre().c_str())));
        tableWidget->setItem(row, 1, new QTableWidgetItem(QString(acutal->getApellido().c_str())));
        tableWidget->setItem(row, 2, new QTableWidgetItem(QString(acutal->getEmail().c_str())));
        tableWidget->setItem(row, 3, new QTableWidgetItem(QString(formatString.str().c_str())));
        QPushButton* boton = new QPushButton("Enviar Solicitud");

        QObject::connect(boton, &QPushButton::clicked, [this, acutal, row, tableWidget](){
            int fila = tableWidget->currentRow();
            capturarRow(fila);
            enviarSolicitud(acutal);
        });

        tableWidget->setCellWidget(row, 4, boton);
        row++;
    }
    tableWidget->resizeColumnsToContents();

}


void MainWindow::cargarSolicitudes(){
    QTableWidget* tableWidget = ui->soliEnviadas;
    SimpleAmistad* cargando = perfil->getEnviados();
    tableWidget->setRowCount(cargando->contador);
    int row = 0;

    while(true){
        Usuario* acutal = cargando->recorreraUno();
        if (acutal == nullptr){
            break;
        }
        tableWidget->setItem(row, 0, new QTableWidgetItem(QString(acutal->getEmail().c_str())));
        QPushButton* cancelar = new QPushButton("Cancelar");

        QObject::connect(cancelar, &QPushButton::clicked, [this,acutal](){
            ui->soliEnviadas->removeRow(ui->soliEnviadas->currentRow());
            addTabla(acutal);
            cancelarSolicitud(acutal);
        });
        ui->soliEnviadas->setCellWidget(row, 1, cancelar);

        row++;
    }
    tableWidget->resizeColumnsToContents();

}

void MainWindow::cargarRecibidos(){
    QTableWidget* tableWidget = ui->soliRecibidas;
    Pila* cargando = perfil->getPila();
    tableWidget->setRowCount(cargando->contador);

    int row = 0;

    while(true){
        Usuario* acutal = cargando->recorreraUno();
        if (acutal == nullptr){
            break;
        }

        tableWidget->setItem(row, 0, new QTableWidgetItem(QString(acutal->getEmail().c_str())));
        QPushButton* enviar = new QPushButton("Aceptar");

        QObject::connect(enviar, &QPushButton::clicked, [this,acutal](){
            ui->soliRecibidas->removeRow(ui->soliRecibidas->currentRow());
            perfil->aceptarSolicitud(acutal);
            cancelarSolicitudP(acutal);
        });
        ui->soliRecibidas->setCellWidget(row, 1, enviar);

        QPushButton* rechazar = new QPushButton("Rechazar");

        QObject::connect(rechazar, &QPushButton::clicked, [this,acutal](){
            ui->soliRecibidas->removeRow(ui->soliRecibidas->currentRow());
            addTabla(acutal);
            cancelarSolicitudP(acutal);
        });
        ui->soliRecibidas->setCellWidget(row, 2, rechazar);
        row++;
    }
    tableWidget->resizeColumnsToContents();
}

void MainWindow::capturarRow(int row){
    filaTabla = row;
}

void MainWindow::enviarSolicitud(Usuario* actual){
    perfil->addSolicitud(actual);
    ui->tablaUsuarios->removeRow(filaTabla);
    filaTabla = 0;
    enviarTabla(actual);
}

void MainWindow::enviarTabla(Usuario* actual){  //Se pasa de la Tabla de Usuario a la tabla de enviados
    ui->soliEnviadas->insertRow(ui->soliEnviadas->rowCount());
    ui->soliEnviadas->setItem(ui->soliEnviadas->rowCount()-1, 0, new QTableWidgetItem(QString(actual->getEmail().c_str())));
    QPushButton* cancelar = new QPushButton("Cancelar");

    QObject::connect(cancelar, &QPushButton::clicked, [this,actual](){
        ui->soliEnviadas->removeRow(ui->soliEnviadas->currentRow());
        addTabla(actual);
        cancelarSolicitud(actual);
    });
    ui->soliEnviadas->setCellWidget(ui->soliEnviadas->rowCount()-1, 1, cancelar);

    ui->soliEnviadas->resizeColumnsToContents();
}

void MainWindow::cancelarSolicitud(Usuario* actual){
    actual->rechazarSolicitud(perfil);
}

void MainWindow::cancelarSolicitudP(Usuario* actual){
    perfil->rechazarSolicitud(actual);
}

void MainWindow::addTabla(Usuario* acutal) {    //Funcion para aniadir objetos individuales a la tabla de Usuarios general
    QTableWidget* tableWidget = ui->tablaUsuarios;
    ui->tablaUsuarios->insertRow(ui->tablaUsuarios->rowCount());
    int row = ui->tablaUsuarios->rowCount()-1;

    time_t fecha = acutal->getFechaNac();
    tm* fechaNac = localtime(&fecha);
    stringstream formatString;
    formatString << put_time(fechaNac, "%Y/%m/%d");
    tableWidget->setItem(row, 0, new QTableWidgetItem(QString(acutal->getNombre().c_str())));
    tableWidget->setItem(row, 1, new QTableWidgetItem(QString(acutal->getApellido().c_str())));
    tableWidget->setItem(row, 2, new QTableWidgetItem(QString(acutal->getEmail().c_str())));
    tableWidget->setItem(row, 3, new QTableWidgetItem(QString(formatString.str().c_str())));
    QPushButton* boton = new QPushButton("Enviar Solicitud");

    QObject::connect(boton, &QPushButton::clicked, [this, acutal, row, tableWidget](){
        int fila = tableWidget->currentRow();
        capturarRow(fila);
        enviarSolicitud(acutal);
    });

    tableWidget->setCellWidget(row, 4, boton);
    tableWidget->resizeColumnsToContents();
}

void MainWindow::cargarPerfil(){
    const char* nombre = perfil->getNombre().c_str();
    ui->nombrePerfil->setText(QString(nombre));

    const char* apellido = perfil->getApellido().c_str();
    ui->apellidoPerfil->setText(QString(apellido));

    const char* correo = perfil->getEmail().c_str();
    ui->correoPerfil->setText(QString(correo));

    const char* pass = perfil->getPass().c_str();
    ui->passPerfil->setText(QString(pass));

    time_t fecha = perfil->getFechaNac();
    QDateTime parseo = QDateTime();
    parseo.setSecsSinceEpoch(fecha);
    ui->nacPerfil->setDateTime(parseo);
}

void MainWindow::actualizarFeed(int value){
    if (listaFeed != nullptr){
        if (regresarInicio){
            Publicacion* actual = listaFeed->recorreraUno();
            if (!actual){
                return;
            }

            QFrame* ventana1 = new QFrame(contenedor);
            QVBoxLayout* scroll = new QVBoxLayout(ventana1);
            ventana1->setMinimumSize(420,435);
            string usuario = actual->getUsuario();

            if (usuario == perfil->getEmail()){
                QPushButton* botonBasura = new QPushButton(ventana1);
                QIcon iconoBasura = style()->standardIcon(QStyle::SP_TrashIcon);
                botonBasura->setIcon(iconoBasura);
                botonBasura->setIconSize(QSize(32, 32));
                scroll->addWidget(botonBasura);
            }

            QFont font("Cascadia Code", 10);
            font.setBold(true);

            QLabel* textFeed = new QLabel(QString(usuario.c_str()), ventana1);
            textFeed->setFont(font);

            time_t fecha = actual->getHora();
            tm* fechaFormat = localtime(&fecha);

            stringstream formatString;
            formatString << put_time(fechaFormat, "%d/%m/%Y %H:%M");

            QLabel* fechaFeed = new QLabel(QString(formatString.str().c_str()), ventana1);
            fechaFeed->setFont(font);

            string texto = actual->getTexto();

            QLabel* contenido = new QLabel(QString(texto.c_str()), ventana1);
            contenido->setWordWrap(true);
            contenido->setFont(font);

            scroll->addWidget(textFeed);
            scroll->addWidget(fechaFeed);
            scroll->addWidget(contenido);

            if (!actual->getImage().empty()){
                QPixmap imagen(actual->getImage().c_str());
                QLabel* ponerImagen = new QLabel(ventana1);
                ponerImagen->setPixmap(imagen);
                scroll->addWidget(ponerImagen);
            }

            layout->insertWidget(0, ventana1);
            bar->setValue(0);
            regresarInicio = false;
        }
        if (value == bar->maximum()){
            Publicacion* actual = listaFeed->recorreraUno();
            if (!actual){
                return;
            }
            QFrame* ventana1 = new QFrame(contenedor);
            QVBoxLayout* scroll = new QVBoxLayout(ventana1);
            ventana1->setMinimumSize(420,435);
            string usuario = actual->getUsuario();
            if (usuario == perfil->getEmail()){
                QPushButton* botonBasura = new QPushButton(ventana1);
                QIcon iconoBasura = style()->standardIcon(QStyle::SP_TrashIcon);
                botonBasura->setIcon(iconoBasura);
                botonBasura->setIconSize(QSize(32, 32));
                scroll->addWidget(botonBasura);
            }

            QFont font("Cascadia Code", 10);
            font.setBold(true);

            QLabel* textFeed = new QLabel(QString(usuario.c_str()), ventana1);
            textFeed->setFont(font);

            time_t fecha = actual->getHora();
            tm* fechaFormat = localtime(&fecha);

            stringstream formatString;
            formatString << put_time(fechaFormat, "%d/%m/%Y %H:%M");

            QLabel* fechaFeed = new QLabel(QString(formatString.str().c_str()), ventana1);
            fechaFeed->setFont(font);

            string texto = actual->getTexto();

            QLabel* contenido = new QLabel(QString(texto.c_str()), ventana1);
            contenido->setWordWrap(true);
            contenido->setFont(font);

            scroll->addWidget(textFeed);
            scroll->addWidget(fechaFeed);
            scroll->addWidget(contenido);
            if (!actual->getImage().empty()){
                QPixmap imagen(actual->getImage().c_str());
                QLabel* ponerImagen = new QLabel(ventana1);
                ponerImagen->setPixmap(imagen.scaled(300,200,Qt::KeepAspectRatio));
                scroll->addWidget(ponerImagen);
            }
            layout->addWidget(ventana1);
        }

    }
}

void MainWindow::on_regresarFeed_clicked()
{
    ui->textPost->clear();
    ui->opPublicacion->setCurrentIndex(0);
    ui->imagenPost->clear();
    ruta = "";
}

string MainWindow::buscarDireccion(){
    QString ruta = QFileDialog::getOpenFileName(this, "Open File", "/",
                                                "JSON Files (*.json);;JPEG Files (*.jpg);;All Files (*.*)");

    if(ruta.isEmpty()){
        return "";
    }
    return ruta.toStdString();
}

void MainWindow::on_buscarImagen_clicked()
{
    ruta = buscarDireccion();

    QPixmap imagen(ruta.c_str());
    ui->imagenPost->setPixmap(imagen.scaled(ui->imagenPost->size(), Qt::KeepAspectRatio));
}

void MainWindow::on_crearPost_clicked()
{
    QString texto = ui->textPost->toPlainText();
    time_t fecha = time(nullptr);
    Publicacion* post = new Publicacion(perfil->getEmail(), texto.toStdString(), fecha);

    if (!ruta.empty()){
        post->setImage(ruta);
    }

    if (texto.isEmpty()){
        delete post;
        return;
    }

    feedGeneral->append(post);
    ABBtree* feed = perfil->getFeed();
    feed->insertar(post);
    ui->textPost->clear();
    ui->opPublicacion->setCurrentIndex(0);
    ui->imagenPost->clear();
    ruta = "";

    if (feed->buscarPublicaciones(post->getFecha())->head->siguiente == nullptr){
        perfil->miFeed->conectar(post->getFecha());
    }

    if (!listaFeed){
        return;
    }

    time_t fech = listaFeed->head->dato->buscarFecha();

    if (fech != post->getFecha()){
        return;
    }

    string user = listaFeed->nombreHead();

    if(user != perfil->getEmail()){
        listaFeed = perfil->miFeed->buscarPublicaciones(post->getFecha());
        delete layout;
        layout = new QVBoxLayout(contenedor);
        actualizarFeed(bar->maximum());
        return;
    }

    listaFeed->nuevo();
    regresarInicio = true;



}

void MainWindow::on_crearPublicacion_clicked()
{
    ui->opPublicacion->setCurrentIndex(1);
}

void MainWindow::on_filtroFech_clicked()
{
    delete layout;
    layout = new QVBoxLayout(contenedor);
    if(perfil->getFeed()->estaVacio()){
        return;
    };
    QDateTime dt = QDateTime(ui->foundPostFecha->date(), QTime(0,0));
    filtroFecha = dt.toSecsSinceEpoch();
    listaFeed = perfil->miFeed->buscarPublicaciones(filtroFecha);
    if (listaFeed){
        listaFeed->activar();
    }else {
        return;
    }
    actualizarFeed(bar->maximum());
}

void MainWindow::limpiarFormCC(){
    ui->newNombre->clear();
    ui->newApellido->clear();
    ui->newCorreo->clear();
    ui->newPass->clear();
    ui->newFecha->clear();
}

void MainWindow::limpiarForm(){
    ui->dataCorreo->clear();
    ui->dataPass->clear();
}


void MainWindow::on_eliminarPerfil_2_clicked()
{
    for(int i = 0; i<ui->tablaUsuarios->rowCount(); i++){
        ui->tablaUsuarios->removeRow(0);
    }
    usuariosGlobal->reset();
    ui->ventanas->setCurrentIndex(0);
}


void MainWindow::on_buscarUsuario_clicked()
{
    ui->showApellido->clear();
    ui->showCorreo->clear();
    ui->showNac->clear();
    ui->showNombre->clear();
    string nombre = ui->correoUsuario->text().toStdString();
    bool verificar = perfil->getMatriz()->buscarAmistad(nombre, perfil->getEmail());
    if (!verificar){
        return;
    }
    Usuario* encontrado  = avl->buscarUsuario(nombre);
    ui->showNombre->setText(QString(encontrado->getNombre().c_str()));
    ui->showApellido->setText(QString(encontrado->getApellido().c_str()));
    ui->showCorreo->setText(QString(encontrado->getEmail().c_str()));
    time_t fecha = encontrado->getFechaNac();
    QDateTime fe;
    fe.setSecsSinceEpoch(fecha);
    ui->showNac->setDateTime(fe);

    ui->correoUsuario->clear();
}


void MainWindow::on_adminBuscando_clicked()
{
    for (int i = 0; i < ui->adminUsuarios->rowCount(); i++){
        ui->adminUsuarios->removeRow(0);
    }
    string buscado = ui->buscarenAdmin->text().toStdString();

    Usuario* encontrado = avl->buscarUsuario(buscado);

    if (!encontrado){
        return;
    }

    ui->adminUsuarios->setRowCount(1);
    ui->adminUsuarios->setItem(0, 0, new QTableWidgetItem(QString(encontrado->getNombre().c_str())));
    ui->adminUsuarios->setItem(0, 1, new QTableWidgetItem(QString(encontrado->getApellido().c_str())));
    ui->adminUsuarios->setItem(0, 2, new QTableWidgetItem(QString(encontrado->getEmail().c_str())));

    time_t fech = encontrado->getFechaNac();
    tm* format = localtime(&fech);

    stringstream formato;
    formato << put_time(format, "%Y/%m/%d");

    ui->adminUsuarios->setItem(0, 3, new QTableWidgetItem(QString(formato.str().c_str())));
}

void MainWindow::on_usarOrden_clicked()
{
    int index = ui->ordenAdmin->currentIndex();
    ui->adminUsuarios->clearContents();
    ui->adminUsuarios->setRowCount(0);

    switch (index) {
    case 0:
        avl->preOrden(ui->editarPerfil,ui->adminUsuarios, avl->root);
        break;
    case 1:
        avl->inOrden(ui->editarPerfil,ui->adminUsuarios, avl->root);
        break;
    case 2:
        avl->postOrden(ui->editarPerfil,ui->adminUsuarios, avl->root);
        break;
    default:
        break;
    }

}


void MainWindow::on_pushButton_3_clicked()
{
    ui->editarPerfil->setCurrentIndex(0);
    ventana = false;
}

MainWindow::~MainWindow(){
    delete ui;
    delete logo;
}

void MainWindow::on_cargaUsuarios_clicked()
{
    string ruta = buscarDireccion();
    if (!ruta.empty()){
        QString archivo(ruta.c_str());
        QFile file (archivo);

        if (file.open(QFile::ReadOnly)){
            QByteArray jsonData = file.readAll();
            file.close();

            QJsonDocument doc = QJsonDocument::fromJson(jsonData);

            if (doc.isArray()){
                QJsonArray root = doc.array();
                foreach (const QJsonValue &v, root) {
                    QJsonObject obj = v.toObject();

                    string nombre = obj.value("nombres").toString().toStdString();
                    string apellido = obj.value("apellidos").toString().toStdString();
                    string fecha = obj.value("fecha_de_nacimiento").toString().toStdString();
                    int anio = std::stoi(fecha.substr(0, 4));
                    int mes = std::stoi(fecha.substr(5, 7));
                    int dia = std::stoi(fecha.substr(8));

                    tm* ingreso = new tm();
                    ingreso->tm_hour = 0;
                    ingreso->tm_mday =dia;
                    ingreso->tm_min = 0;
                    ingreso->tm_mon = mes-1;
                    ingreso->tm_sec = 0;
                    ingreso->tm_year = anio-1900;

                    time_t fechaformat = mktime(ingreso);
                    string correo = obj.value("correo").toString().toStdString();
                    string pass = obj.value("contraseña").toString().toStdString();

                    Usuario* nuevo = new Usuario(nombre, apellido, fechaformat, correo, pass);
                    avl->insertar(nuevo);
                }
            }else{
                 QMessageBox::warning(this, "Error", "El archivo JSON no es un array.");
            }

        }else{
            QMessageBox::warning(this, "Error", "No se pudo abrir el archivo.");
        }
    }



}


void MainWindow::on_cargaSoli_clicked()
{
    string ruta = buscarDireccion();
    if (!ruta.empty()){
        QString archivo(ruta.c_str());
        QFile file (archivo);

        if (file.open(QFile::ReadOnly)){
            QByteArray jsonData = file.readAll();
            file.close();

            QJsonDocument doc = QJsonDocument::fromJson(jsonData);

            if (doc.isArray()){
                QJsonArray root = doc.array();
                foreach (const QJsonValue &v, root) {
                    QJsonObject obj = v.toObject();

                    string emisor = obj.value("emisor").toString().toStdString();
                    string recpertor = obj.value("receptor").toString().toStdString();
                    string estado = obj.value("estado").toString().toStdString();
                }
            }else{
                QMessageBox::warning(this, "Error", "El archivo JSON no es un array.");
            }

        }else{
            QMessageBox::warning(this, "Error", "No se pudo abrir el archivo.");
        }
    }
}

