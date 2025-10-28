#include "playing_cards.h"
#include <random>

#include <algorithm>
using namespace cards;

void shuffle_deck(Deck& deck) {
    std::random_device rd;
    std::mt19937 gen{rd()};
    std::ranges::shuffle(deck, gen);
}

int main() {
    auto deck = create_deck();
    shuffle_deck(deck);
    for (auto& card : deck) {
        std::cout << card << '\n';
    }
}