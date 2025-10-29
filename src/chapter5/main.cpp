#include "playing_cards.h"
#include <random>

#include <algorithm>
using namespace cards;

void shuffle_deck(Deck& deck) {
    std::random_device rd;
    std::mt19937 gen{rd()};
    std::ranges::shuffle(deck, gen);
}

bool is_guess_correct(const char guess, const Card& current, const Card& next) {
    return (guess == 'h' && next > current) | (guess == 'l' && next < current);
}

void higher_lower() {
    auto deck = create_deck();
    shuffle_deck(deck);

    size_t index = 0;
    while (index + 1 < deck.size()) {
        std::cout << deck[index] << ": Next card (h)igher or (l)ower?\n";
        char c;
        std::cin >> c;
        if (const bool ok = is_guess_correct(c, deck[index], deck[index + 1]); !ok) {
            std::cout << "Next card was " << deck[index + 1] << '\n';
            break;
        }
        ++index;
    }

    std::cout << "You got " << index << " correct\n";
}

int main() {
    higher_lower();
}