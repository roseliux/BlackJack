#include "deck.h"

Deck::Deck()
{
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 13; j++){
            cards.push_back(Card(Rank(j),Suit(i)));

        }
    }

}

void Deck::Print(){

    for(int i = 0; i<int(cards.size());i++){
        cards[i].Print();
    }
}

void Deck::Shuffle(){

    std::srand ( unsigned ( std::time(0) ) );
    std::random_shuffle(cards.begin(),cards.end());

}

Card Deck::TakeTopCard(){


    if(!cards.empty()){

        Card topCard(cards[cards.size()-1].rank,cards[cards.size()-1].suit);
        cards.pop_back(); // remove last card
        return topCard;

    }
    else{
        qDebug() << " Esta vacio crear messagebox!!!";
    }

}
