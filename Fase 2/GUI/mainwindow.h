#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../Estructuras/AVLtree.h"
#include "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 1/Estructuras/EnlazadaDoble.cpp"

#include <QMainWindow>
#include <QLabel>
#include <QPixmap>
#include <QFrame>
#include <QMessageBox>
#include <QDate>
#include <QVBoxLayout>
#include <QScrollBar>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_botonCC_clicked();

    void on_back0_clicked();

    void on_newUsuario_clicked();

    void on_botonIS_clicked();

    void actualizarFeed(int value);

private:
    Ui::MainWindow *ui;

    int rango = 100;

    QMessageBox* mensajeIS = nullptr;
    QLabel* logo = nullptr;
    QWidget *contenedor = nullptr;
    QVBoxLayout *layout = nullptr;
    QScrollBar* bar = nullptr;

    Usuario* perfil = nullptr;
    Usuario* admin = nullptr;
    AVLtree* avl = nullptr;
    DoublyLinkedList* feedGeneral = nullptr;

    void iniciarLogo();
    void frameMain();
    void cargarPerfil();
    void cargarPublicacion();

    void limpiarFormCC();
    void limpiarForm();

};
#endif // MAINWINDOW_H
