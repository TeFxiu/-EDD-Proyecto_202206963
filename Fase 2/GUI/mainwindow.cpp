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
    contenedor = new QWidget;
    layout = new QVBoxLayout(contenedor);
    bar = ui->scrollArea->verticalScrollBar();

    connect(bar, &QScrollBar::valueChanged, this, &MainWindow::actualizarFeed);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete logo;
}

void MainWindow::iniciarLogo(){
    QFrame* inicio = ui->frameIS;

    logo = new QLabel(inicio);

    QPixmap pix("C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 2/Logo.png");

    logo->setPixmap(pix.scaled(200, 200, Qt::KeepAspectRatio));

    logo->setGeometry(this->width()/2-100, this->height()/8, 200, 100);

    logo->show();

}

void MainWindow::frameMain(){
    ui->ventanas->setCurrentIndex(0);
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


void MainWindow::on_newUsuario_clicked()
{
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


void MainWindow::on_botonIS_clicked()
{

    cargarPublicacion();
    limpiarForm();
    ui->ventanas->setCurrentIndex(2);
    /*
    string stdCorreo = ui->dataCorreo->text().toStdString();
    string stdPass = ui->dataPass->text().toStdString();

    if (stdCorreo == admin->getEmail() && stdPass == admin->getPass()){
        ui->ventanas->setCurrentIndex(1);
    }

    perfil = avl->buscarUsuario(stdCorreo);

    if (perfil != nullptr){
        if (perfil->getPass() == stdPass){
            cargarPerfil();
            cargarPublicacion();
            limpiarForm();
            ui->ventanas->setCurrentIndex(2);
            return ;
        }
    }

    mensajeIS->setText("Datos invalido");
    mensajeIS->show();
*/
}

void MainWindow::actualizarFeed(int value){
    if (value == bar->maximum()){
    QFrame* ventana1 = new QFrame(contenedor);

    QVBoxLayout* scroll = new QVBoxLayout(ventana1);

    ventana1->setMinimumSize(420,435);

    QLabel* las = new QLabel(QString("dfdf"), ventana1);

    las->setText("sdsdsd");

    QPushButton * bon = new QPushButton("Min", ventana1);
    scroll->addWidget(bon);

    scroll->addWidget(las);

    layout->addWidget(ventana1);
    }
    return;
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

void MainWindow::cargarPublicacion(){

    QFrame* ventana1 = new QFrame(contenedor);

    QVBoxLayout* scroll = new QVBoxLayout(ventana1);

    ventana1->setMinimumSize(420,435);

    QLabel* las = new QLabel(QString("dfdf"), ventana1);

    las->setText("sdsdsd");

    QPushButton * bon = new QPushButton("Min", ventana1);
    scroll->addWidget(bon);

    scroll->addWidget(las);

    layout->addWidget(ventana1);

    ui->scrollArea->setWidget(contenedor);
    contenedor->resize(ui->scrollArea->size());

}

void MainWindow::limpiarFormCC(){
    ui->newNombre->clear();
    ui->newApellido->clear();
    ui->newCorreo->clear();
    ui->newPass->clear();
}

void MainWindow::limpiarForm(){
    ui->dataCorreo->clear();
    ui->dataPass->clear();
}
