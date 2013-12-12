#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include "mainwindowmesa.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    //void on_pushButtonJugar_2_clicked();

    void on_pushButtonInstrucciones_clicked();

    void on_pushButtonJugar_clicked();

private:
    QDialog *qdialog;
    Ui::MainWindow *ui;
    MainWindowMesa *mesa;
    /*
private Slot:
    void nuevaventana();*/
};

#endif // MAINWINDOW_H
