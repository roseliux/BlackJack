#ifndef MAINWINDOWMESA_H
#define MAINWINDOWMESA_H

#include <QMainWindow>
#include"blackjack.h"

namespace Ui {
class MainWindowMesa;
}

class MainWindowMesa : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowMesa(QWidget *parent = 0);
    ~MainWindowMesa();
    BlackJack player;
    MainWindowMesa *z;
    BlackJack croupier;
    Deck deck;
    int spaceplayer;
    int spacecroupier;
    // methods
    void first_deal();

private slots:
    void on_pushButtonRegresar_clicked();

    void on_pushButtonDEAL_clicked();

    void on_pushButtonPedir_clicked();

    void on_pushButtonPlantarse_clicked();

private:
    Ui::MainWindowMesa *ui;
};

#endif // MAINWINDOWMESA_H
