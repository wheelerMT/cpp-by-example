#include "playing_cards.h"
using namespace cards;

bool is_guess_correct(const char guess, const Card& current, const Card& next) {
    return (guess == 'h' && next > current) | (guess == 'l' && next < current);
}

bool is_guess_correct(const char guess, const std::variant<Card, Joker>& current,
                      const std::variant<Card, Joker>& next) {
    if (std::holds_alternative<Joker>(current) || std::holds_alternative<Joker>(next))
        return true;

    const Card current_card = std::get<Card>(current);
    const Card next_card = std::get<Card>(next);
    return is_guess_correct(guess, current_card, next_card);
}

void higher_lower() {
    auto deck = create_extended_deck();
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