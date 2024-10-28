#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../Estructuras/AVLtree.h"
#include "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 1/Estructuras/EnlazadaDoble.cpp"
#include "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 1/Estructuras/SimpleAmistad.cpp"
#include "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 1/Estructuras/Pila.cpp"
#include "../Estructuras/ListaUsuarios.h"
#include "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 3/Estructuras/Grafo.h"

#include <QCryptographicHash>
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

    void on_buscarUsuario_clicked();

    void on_adminBuscando_clicked();

    void on_usarOrden_clicked();

    void on_pushButton_3_clicked();

    void cargaEdicion();

    void on_cargaUsuarios_clicked();

    void on_cargaSoli_clicked();

    void on_pushButton_4_clicked();

    void on_publicarComent_clicked();

    void on_cargarPosts_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_modificarPerfil_clicked();

    void on_pushButton_6_clicked();

    void on_pp_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::MainWindow *ui;

    QMessageBox* mensajeIS = nullptr;
    QLabel* logo = nullptr; // Label donde se muestra la imagen del logo
    QWidget *contenedor = nullptr; // Los siguientes 3 son los necesarios para crear el feed de publicaciones
    QVBoxLayout *layout = nullptr;
    QScrollBar* bar = nullptr;

    Usuario* perfil = nullptr; // Perfil actual que inicio sesio
    Usuario* admin = nullptr;
    Usuario* editar = nullptr;

    AVLtree* avl = nullptr; //Arbol de usuarios
    DoublyLinkedList* feedGeneral = nullptr; // Lista enlazada doble donde se guardan todas las publicaciones
    ListaPosts* listaFeed = nullptr;
    ListaUsuarios* usuariosGlobal = nullptr;
    ListaUsuarios* recomendados = nullptr;
    Publicacion* comentando = nullptr;
    Grafo* amistades = nullptr;
    PostSimple* recorrido;

    string buscarDireccion();
    string ruta = "";

    bool ventana = false;

    int filaTabla = 0;
    void capturarRow(int fila);
    time_t filtroFecha = 0;

    bool regresarInicio = false;

    void agregarComentario(Publicacion* dato);
    void iniciarLogo();
    void frameMain();
    void cargarPerfil();
    void cargarPublicacion();
    void cargarTabla();
    void cargarRecomendaciones();
    void enviarSolicitud(Usuario* actual);
    void enviarTabla(Usuario* tabla);
    void addTabla(Usuario* actual);
    void cancelarSolicitud(Usuario* actual);
    void cancelarSolicitudP(Usuario* actual);
    void cargarSolicitudes();
    void cargarRecibidos();
    void limpiarFormCC();
    void limpiarForm();
    void crearBloque(Publicacion* post);

};
#endif // MAINWINDOW_H
