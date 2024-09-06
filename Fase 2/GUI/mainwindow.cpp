#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    iniciarLogo();
    frameMain();

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
    ui->dataCorreo->clear();
    ui->dataPass->clear();
    ui->ventanas->setCurrentIndex(2);
}


void MainWindow::on_back0_clicked()
{
    limpiarForm();
    ui->ventanas->setCurrentIndex(0);
}


void MainWindow::on_newUsuario_clicked()
{
    limpiarForm();
    ui->ventanas->setCurrentIndex(0);
}

void MainWindow::limpiarForm(){
    ui->newNombre->clear();
    ui->newApellido->clear();
    ui->newCorreo->clear();
    ui->newPass->clear();
}


void MainWindow::on_botonIS_clicked()
{
    ui->dataCorreo->clear();
    ui->dataPass->clear();
    ui->ventanas->setCurrentIndex(1);
}

