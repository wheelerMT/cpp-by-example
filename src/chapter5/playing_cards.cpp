//
// Created by Matthew Wheeler on 21/10/2025.
//

#include "playing_cards.h"

#include <algorithm>

namespace cards {
std::string to_string(const Suit& suit) {
    using namespace std::literals;
    switch (suit) {
    case Suit::Hearts:
        return "Hearts"s;
    case Suit::Diamonds:
        return "Diamonds"s;
    case Suit::Clubs:
        return "Clubs"s;
    case Suit::Spades:
        return "Spades"s;
    default:
        return "?"s;
    }
}

std::string to_string(const FaceValue& value) {
    using namespace std::literals;
    switch (value.value()) {
    case 1:
        return "Ace"s;
    case 11:
        return "Jack"s;
    case 12:
        return "Queen"s;
    case 13:
        return "King"s;
    default:
        return std::to_string(value.value());
    }
}
Suit& operator++(Suit& suit) {
    using IntType = std::underlying_type_t<Suit>;
    if (suit == Suit::Spades)
        suit = Suit::Hearts;
    else
        suit = static_cast<Suit>(static_cast<IntType>(suit) + 1);
    return suit;
}

std::array<Card, 52> create_deck() {
    std::array<Card, 52> deck;
    int value = 1;
    auto suit = Suit::Hearts;

    std::ranges::generate(deck, [&value, &suit]() {
        if (value > 13) {
            value = 1;
            ++suit;
        }
        return Card{FaceValue(value++), suit};
    });
    return deck;
}

std::ostream& operator<<(std::ostream& os, const Card& card) {
    os << to_string(card.value()) << " of " << to_string(card.suit());
    return os;
}

} // namespace cards