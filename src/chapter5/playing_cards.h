//
// Created by Matthew Wheeler on 21/10/2025.
//

#ifndef CHAPTER5_PLAYING_CARDS_H
#define CHAPTER5_PLAYING_CARDS_H
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

struct Card {
    FaceValue value;
    Suit suit;
};

} // namespace cards
#endif // CHAPTER5_PLAYING_CARDS_H
