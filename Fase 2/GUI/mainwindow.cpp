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
}

void MainWindow::frameMain(){
    ui->ventanas->setCurrentIndex(0);
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
    QString ruta = QFileDialog::getOpenFileName(this, "Open File", "/", "Text Files(*.jpg);;All Files (*,*)");

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

MainWindow::~MainWindow(){
    delete ui;
    delete logo;
}

void MainWindow::on_eliminarPerfil_2_clicked()
{
    for(int i = 0; i<ui->tablaUsuarios->rowCount(); i++){
        ui->tablaUsuarios->removeRow(0);
    }
    usuariosGlobal->reset();
    ui->ventanas->setCurrentIndex(0);
}

