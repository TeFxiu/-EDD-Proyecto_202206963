#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../Estructuras/AVLtree.h"
#include "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 1/Estructuras/EnlazadaDoble.cpp"
#include "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 1/Estructuras/SimpleAmistad.cpp"
#include "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 1/Estructuras/Pila.cpp"
#include "../Estructuras/ListaUsuarios.h"

#include <QFileDialog>
#include <QMainWindow>
#include <QLabel>
#include <QPixmap>
#include <QFrame>
#include <QMessageBox>
#include <QDate>
#include <QVBoxLayout>
#include <QScrollBar>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>


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

    void on_crearPublicacion_clicked();

    void on_regresarFeed_clicked();

    void on_buscarImagen_clicked();

    void on_crearPost_clicked();

    void on_filtroFech_clicked();

    void on_eliminarPerfil_2_clicked();

private:
    Ui::MainWindow *ui;

    QMessageBox* mensajeIS = nullptr;
    QLabel* logo = nullptr;
    QWidget *contenedor = nullptr;
    QVBoxLayout *layout = nullptr;
    QScrollBar* bar = nullptr;

    Usuario* perfil = nullptr;
    Usuario* admin = nullptr;
    AVLtree* avl = nullptr;
    DoublyLinkedList* feedGeneral = nullptr;
    ListaPosts* listaFeed = nullptr;
    ListaUsuarios* usuariosGlobal = nullptr;

    string buscarDireccion();
    string ruta = "";

    int filaTabla = 0;
    void capturarRow(int fila);
    time_t filtroFecha = 0;

    bool regresarInicio = false;

    void iniciarLogo();
    void frameMain();
    void cargarPerfil();
    void cargarPublicacion();
    void cargarTabla();
    void enviarSolicitud(Usuario* actual);
    void enviarTabla(Usuario* tabla);
    void addTabla(Usuario* actual);
    void cancelarSolicitud(Usuario* actual);
    void cancelarSolicitudP(Usuario* actual);
    void cargarSolicitudes();
    void cargarRecibidos();

    void limpiarFormCC();
    void limpiarForm();

};
#endif // MAINWINDOW_H
