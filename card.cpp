#include "card.h"

Card::Card(Rank rank_, Suit suit_)
{
    rank = rank_;
    suit = suit_;
    faceUp = false;
    blackJackValue = get_blackJackValue();

}

QString Card::get_rank(){

    switch(rank){

    case Ace:
        return QString("Ace");
    case Two:
        return QString("Two");
    case Three:
        return QString("Three");
    case Four:
        return QString("Four");
    case Five:
        return QString("Five");
    case Six:
        return QString("Six");
    case Seven:
        return QString("Seven");
    case Eight:
        return QString("Eight");
    case Nine:
        return QString("Nine");
    case Ten:
        return QString("Ten");
    case Jack:
        return QString("Jack");
    case Queen:
        return QString("Queen");
    case King:
        return QString("King");
    default:
        return QString("None");
    }

}
QString Card::get_suit(){
    switch(suit){
    case Clubs:
        return QString("Clubs");
    case Diamonds:
        return QString("Diamonds");
    case Hearts:
        return QString("Hearts");
    case Spades:
        return QString("Spades");
    default:
        return QString("None");

    }
}
bool Card::get_faceUp(){

    return faceUp;

}
int Card::get_blackJackValue(){

    switch(rank){
    case Ace:
        return 11;
    case Two:
        return 2;
    case Three:
        return 3;
    case Four:
        return 4;
    case Five:
        return 5;
    case Six:
        return 6;
    case Seven:
        return 7;
    case Eight:
        return 8;
    case Nine:
        return 9;
    case Ten:
        return 10;
    case Jack:
        return 10;
    case Queen:
        return 10;
    case King:
        return 10;
    default:
        return 0;
    }
}
void Card::FlipOver(){

    faceUp = !faceUp;

}
QString Card::get_card_image(){
///cards/FourSpades.png
    QString res("/cards/");
    res.append(get_rank());
    res.append(get_suit());
    res.append(".png");

    return res;

}

void Card::Print(){

    if(faceUp){
        qDebug() << get_rank() << " of " <<
                    get_suit() ;
    }
    else{

        qDebug() << " Face down card " ;

    }
}
