#include "blackjack.h"

BlackJack::BlackJack(): MAX_HAND_VALUE(21)
{
}

int BlackJack::get_score(){

    int numAces = 0;
    int score = 0;

    for(int i = 0; i < int(cards.size()); i++){

        if(cards[i].rank != 0){

            score += cards[i].get_blackJackValue();

        }
        else{
            numAces++;
        }

    }
    // if more than one ace, only one should ever be counted as 11
    if(numAces > 1){
        //make all but the first ace count as 1
        score += numAces - 1;
        numAces = 1;
    }

    if(numAces > 0){
        if(score + 11 <= MAX_HAND_VALUE){
            score += 11;
        }
        else{
            score++;
        }
    }
    return score;
}
void BlackJack::AddCard(Card card){
    cards.push_back(card);
}
void BlackJack::HitOrNot(Deck deck){

    if(hit){

        Card c = deck.TakeTopCard();
        if(c.get_faceUp() == false){
            c.FlipOver();
        }
        cards.push_back(c);

    }
}
void BlackJack::ShowFirstCard(){

    if(cards.empty() == false &&
       cards[0].get_faceUp() == false){

        cards[0].FlipOver();

    }
}
void BlackJack::ShowAllCards(){

    for(int i = 0; i < int(cards.size()); i++){
        if(cards[i].get_faceUp() == false){
            cards[i].FlipOver();
        }
    }
}

void BlackJack::Print(){

    for(int i = 0; i < int(cards.size()); ++i){
        cards[i].Print();
    }
}

std::vector<Card> BlackJack::get_Cards(){
   return cards;
}
