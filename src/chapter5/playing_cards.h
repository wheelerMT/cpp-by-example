//
// Created by Matthew Wheeler on 21/10/2025.
//

#ifndef CHAPTER5_PLAYING_CARDS_H
#define CHAPTER5_PLAYING_CARDS_H
#include <iostream>
#include <stdexcept>
#include <variant>

namespace cards {
enum class Suit { Hearts, Diamonds, Clubs, Spades };

class FaceValue {
public:
    explicit FaceValue(const int value)
        : m_value(value) {
        if (m_value < 1 || m_value > 13) {
            throw std::invalid_argument("Face value invalid, must be between 1 and 13");
        }
    }
    [[nodiscard]] int value() const {
        return m_value;
    }
    auto operator<=>(const FaceValue&) const = default;

private:
    int m_value;
};

class Card {
public:
    Card() = default;
    Card(const FaceValue value, const Suit suit)
        : m_value{value}
        , m_suit{suit} {}
    [[nodiscard]] FaceValue value() const {
        return m_value;
    }
    [[nodiscard]] Suit suit() const {
        return m_suit;
    }
    auto operator<=>(const Card&) const = default;

private:
    FaceValue m_value{1};
    Suit m_suit{};
};

struct Joker {};

using Deck = std::array<Card, 52>;
Deck create_deck();

using ExtendedDeck = std::array<std::variant<Card, Joker>, 52>;
ExtendedDeck create_extended_deck();

void shuffle_deck(Deck& deck);
void shuffle_deck(ExtendedDeck& deck);

std::ostream& operator<<(std::ostream& os, const Card& card);
std::ostream& operator<<(std::ostream& os, const std::variant<Card, Joker>& card);
std::string to_string(const Suit& suit);
std::string to_string(const FaceValue& value);
Suit& operator++(Suit& suit);

} // namespace cards
#endif // CHAPTER5_PLAYING_CARDS_H
