#include "mainwindowmesa.h"
#include "ui_mainwindowmesa.h"
#include "mainwindow.h"
#include <QLabel>
#include "blackjack.h"
#include "card.h"
#include "deck.h"
#include <QDebug>
#include <QDialog>
#include <QMessageBox>
#include <QtGui>
#include <QIcon>

MainWindowMesa::MainWindowMesa(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowMesa)
{
    spaceplayer=250;
    ui->setupUi(this);
    ui->pushButtonPedir->setEnabled(false);
    ui->pushButtonPlantarse->setEnabled(false);

}

MainWindowMesa::~MainWindowMesa()
{
    delete ui;
}

void MainWindowMesa::on_pushButtonRegresar_clicked()
{
    this->close();
    MainWindow *a = new MainWindow;
    a->show();

}

void MainWindowMesa::on_pushButtonDEAL_clicked()
{
    first_deal();
    /*deck.Shuffle();
    player.AddCard(deck.TakeTopCard());
    player.AddCard(deck.TakeTopCard());
    croupier.AddCard(deck.TakeTopCard());
    croupier.AddCard(deck.TakeTopCard());
    player.ShowAllCards();
    croupier.ShowFirstCard();*/
    std::vector<Card> plyrcards=player.get_Cards();
    std::vector<Card> croupiercards=croupier.get_Cards();

    QLabel *cardplyr1 = new QLabel(this);
    QLabel *cardplyr2 = new QLabel(this);
    QLabel *cardcroupier1 = new QLabel(this);
    QLabel *cardcroupier2 = new QLabel(this);

    cardplyr1->setGeometry(QRect(235,300,100,100));
    cardplyr2->setGeometry(QRect(250,300,100,100));
    spacecroupier=200;
    cardcroupier1->setGeometry(QRect(130,75,100,100));
    cardcroupier2->setGeometry(QRect(spacecroupier,75,100,100));

    QString file=plyrcards[0].get_card_image();
    cardplyr1->setStyleSheet("image: url(:"+file+");");
    file=plyrcards[1].get_card_image();
    cardplyr2->setStyleSheet("image: url(:"+file+");");
    file=croupiercards[1].get_card_image();
    cardcroupier2->setStyleSheet("image: url(:"+file+");");
    cardcroupier1->setStyleSheet("image: url(:/cards/backcard.png);");//facedown
    cardplyr1->show();
    cardplyr2->show();
    cardcroupier1->show();
    cardcroupier2->show();
    QString scp;
    ui->scp->setText(scp.setNum(player.get_score()));
    //qDebug()<<player.get_score();
    ui->pushButtonDEAL->setEnabled(false);
    if(player.get_score()!=21){
        ui->pushButtonPedir->setEnabled(true);
        ui->pushButtonPlantarse->setEnabled(true);
    }
    else if(player.get_score() == 21){
        ui->scp->setText(scp.setNum(player.get_score()));
        ui->pushButtonPedir->setEnabled(false);
        //QMessageBox::information(this, "RESULTADO","BLACK JACK 21! GANASTE!");
        QMessageBox res;
        res.setText("BLACK JACK");
        res.setInformativeText("GANASTE 21");
        res.setIcon(QMessageBox::Information);
        res.exec();
        this->close();
        z=new MainWindowMesa(this);
        z->show();
    }

}

void MainWindowMesa::on_pushButtonPedir_clicked()
{
    std::vector<Card> plyrcards=player.get_Cards();
    //if(player.get_score()<=21){
        player.AddCard(deck.TakeTopCard());
        player.ShowAllCards();
        plyrcards=player.get_Cards();        
        QString scp;
        ui->scp->setText(scp.setNum(player.get_score()));
        QLabel *card = new QLabel(this);
        spaceplayer+=15;
        card->setGeometry(QRect(spaceplayer,300,100,100));

        QString file=plyrcards[plyrcards.size()-1].get_card_image();

        card->setStyleSheet("image: url(:"+file+");");
        card->show();
        //qDebug()<<player.get_score();
        if(player.get_score()>21){
            plyrcards=player.get_Cards();
            ui->pushButtonPedir->setEnabled(false);
            //QMessageBox::information(this, "RESULTADO","Te pasaste de 21! PERDISTE" );
            QMessageBox res;
            res.setText("PERDISTE!");
            res.setInformativeText("Te pasaste de 21.");
            res.setIcon(QMessageBox::Warning);
            res.exec();
            this->close();
            z=new MainWindowMesa(this);
            z->show();
        }
        else if(player.get_score()==21){
            plyrcards=player.get_Cards();
            ui->pushButtonPedir->setEnabled(false);
            //QMessageBox::information(this, "RESULTADO","BLACK JACK 21! GANASTE!");
            QMessageBox res;
            res.setText("GANASTE!");
            res.setInformativeText("Black Jack 21!");
            res.setIcon(QMessageBox::Information);
            res.exec();
            this->close();
            z=new MainWindowMesa(this);
            z->show();
        }

}

void MainWindowMesa::first_deal(){

   deck.Shuffle();
   player.AddCard(deck.TakeTopCard());
   player.AddCard(deck.TakeTopCard());
   croupier.AddCard(deck.TakeTopCard());
   croupier.AddCard(deck.TakeTopCard());
   player.ShowAllCards();
   croupier.ShowFirstCard();

}


void MainWindowMesa::on_pushButtonPlantarse_clicked()
{
    croupier.ShowAllCards();
    std::vector<Card> croupiercards=croupier.get_Cards();
    QString scp;
    ui->scp->setText(scp.setNum(player.get_score()));
    QLabel *croupiercard1 = new QLabel(this);
    croupiercard1->setGeometry(QRect(130,75,100,100));
    QString file=croupiercards[0].get_card_image();
    croupiercard1->setStyleSheet("image: url(:"+file+");");
    croupiercard1->show();
    bool a = false;

    while(croupier.get_score()<17){
        a = true;
        // croupier empiza a pedir
        croupier.AddCard(deck.TakeTopCard());
        croupier.ShowAllCards();
        croupiercards=croupier.get_Cards();
        QLabel *card = new QLabel(this);
        spacecroupier+=15;
        card->setGeometry(QRect(spacecroupier,75,100,100));
        QString file=croupiercards[croupiercards.size()-1].get_card_image();
        card->setStyleSheet("image: url(:"+file+");");
        card->show();
        //QString scp;
        //ui->scc->setText(scp.setNum(croupier.get_score()));

        if(croupier.get_score()>21){
            QString scrp;
            QString scrc;
            QString msg2 = "El croupier se paso de 21! \nTu Score fue: "+scrp.setNum(player.get_score())+" \nCroupier fue: "+scrc.setNum(croupier.get_score());
            //QMessageBox::information(this, "RESULTADO",msg2);
            QMessageBox res;
            res.setText("GANASTE!");
            res.setInformativeText(msg2);
            res.setIcon(QMessageBox::Information);
            res.exec();
            this->close();
            z=new MainWindowMesa(this);
            z->show();
            break;
        }
        else if((player.get_score()>croupier.get_score()) && (croupier.get_score() >= 17 && croupier.get_score() <= 20)){
                QString scrp;
                QString scrc;
                QString msg2 = "Hiciste lenia al croupier! \nTu Score fue: "+scrp.setNum(player.get_score())+"\n Croupier fue: "+scrc.setNum(croupier.get_score());
                //QMessageBox::information(this, "RESULTADO",msg2);
                QMessageBox res;
                res.setText("GANASTE!");
                res.setInformativeText(msg2);
                res.setIcon(QMessageBox::Information);
                res.exec();
                this->close();
                z=new MainWindowMesa(this);
                z->show();
                break;
        }
        else if((player.get_score()==croupier.get_score())){
                QString scrp;
                QString scrc;
                QString msg2 = "Tu Score fue: "+scrp.setNum(player.get_score())+" \nCroupier fue: "+scrc.setNum(croupier.get_score());
                //QMessageBox::information(this, "RESULTADO",msg2);
                QMessageBox res;
                res.setText("EMPATE!");
                res.setIcon(QMessageBox::Warning);
                res.setInformativeText(msg2);
                res.exec();
                this->close();
                z=new MainWindowMesa(this);
                z->show();
                break;
        }
        else if(player.get_score() < 21 && croupier.get_score() == 21){

            QString scrp;
            QString scrc;
            QString msg2 = "Tu Score fue: "+scrp.setNum(player.get_score())+" \nCroupier: "+scrc.setNum(croupier.get_score());
            //QMessageBox::information(this, "RESULTADO",msg2);
            QMessageBox res;
            res.setText("PERDISTE!");
            res.setInformativeText(msg2);
            res.setIcon(QMessageBox::Critical);
            res.exec();
            this->close();
            z=new MainWindowMesa(this);
            z->show();
            break;
        }
        else if(croupier.get_score() > player.get_score() && croupier.get_score() <= 21){
            QString scrp;
            QString scrc;
            QString msg2 = "Tu Score fue: "+scrp.setNum(player.get_score())+" \nCroupier fue: "+scrc.setNum(croupier.get_score());
            //QMessageBox::information(this, "RESULTADO",msg2);
            QMessageBox res;
            res.setText("PERDISTE!");
            res.setInformativeText(msg2);
            res.setIcon(QMessageBox::Critical);
            res.exec();
            this->close();
            z=new MainWindowMesa(this);
            z->show();
            break;

        }

    }
    if(a == false){
        if((player.get_score()<croupier.get_score()) && croupier.get_score()<22){
            QString scrp;
            QString scrc;
            QString msg2 = "El croupier te hizo lenia! \nTu Score fue: "+scrp.setNum(player.get_score())+" \nCroupier fue: "+scrc.setNum(croupier.get_score());
            //QMessageBox::information(this, "RESULTADO",msg2);
            QMessageBox res;
            res.setText("PERDISTE!");
            res.setIcon(QMessageBox::Critical);
            res.setInformativeText(msg2);
            res.exec();
            this->close();
            z=new MainWindowMesa(this);
            z->show();
        }
        else if(croupier.get_score() < player.get_score() && croupier.get_score()<22){
            QString scrp;
            QString scrc;
            QString msg2 = "Tu Score fue: "+scrp.setNum(player.get_score())+" \nCroupier fue: "+scrc.setNum(croupier.get_score());
            //QMessageBox::information(this, "RESULTADO",msg2);
            QMessageBox res;
            res.setText("GANASTE!");
            res.setIcon(QMessageBox::Information);
            res.setInformativeText(msg2);
            res.exec();
            this->close();
            z=new MainWindowMesa(this);
            z->show();
        }
        else if((player.get_score()==croupier.get_score())&& croupier.get_score()<22){
                QString scrp;
                QString scrc;
                QString msg2 = "Tu Score fue: "+scrp.setNum(player.get_score())+" \nCroupier fue: "+scrc.setNum(croupier.get_score());
                //QMessageBox::information(this, "RESULTADO",msg2);
                QMessageBox res;
                res.setText("EMPATE!");
                res.setInformativeText(msg2);
                res.setIcon(QMessageBox::Warning);
                res.exec();
                this->close();
                z=new MainWindowMesa(this);
                z->show();
        }
    }



}
