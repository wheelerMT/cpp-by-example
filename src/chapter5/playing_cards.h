//
// Created by Matthew Wheeler on 21/10/2025.
//

#ifndef CHAPTER5_PLAYING_CARDS_H
#define CHAPTER5_PLAYING_CARDS_H
#include <iostream>
#include <stdexcept>

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

private:
    FaceValue m_value{1};
    Suit m_suit{};
};

std::ostream& operator<<(std::ostream& os, const Card& card);

} // namespace cards
#endif // CHAPTER5_PLAYING_CARDS_H
