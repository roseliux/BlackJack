#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <vector>
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

class Deck
{
    std::vector<Card> cards;

public:
    Deck();
    // methods
    void Shuffle(); // Shuffles the deck
    //int myrandom (int i) { return std::rand()%i;}
    void Print(); // Prints the contents of the deck
    Card TakeTopCard();
};

#endif // DECK_H
