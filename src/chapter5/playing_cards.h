//
// Created by Matthew Wheeler on 21/10/2025.
//

#ifndef CHAPTER5_PLAYING_CARDS_H
#define CHAPTER5_PLAYING_CARDS_H
namespace cards {
enum class Suit { Hearts, Diamonds, Clubs, Spades };

struct Card {
    int value;
    Suit suit;
};
} // namespace cards
#endif // CHAPTER5_PLAYING_CARDS_H
