#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPixmap>
#include <QFrame>

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

private:
    Ui::MainWindow *ui;
    QLabel* logo = nullptr;

    void iniciarLogo();
    void frameMain();
    void limpiarForm();

};
#endif // MAINWINDOW_H
