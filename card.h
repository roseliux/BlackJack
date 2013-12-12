#ifndef CARD_H
#define CARD_H

#include "rank_and_suit.h"
#include <QString>
#include <QDebug>

class Card
{

    // Fields and properties
    bool faceUp;
    int blackJackValue;


public:

    Rank rank;
    Suit suit;

    Card(Rank, Suit);
    // getters
    QString get_rank();
    QString get_suit();
    bool get_faceUp();
    int get_blackJackValue(); //get black jack value(stack)
    QString get_card_image();

    //methods
    void FlipOver(); // to change the faceUp value.
    void Print(); // to print in console

    //overload operator =
    Card& operator = (Card b){
        this->rank = b.rank;
        this->suit = b.suit;
        return *this;
    }
};

#endif // CARD_H
