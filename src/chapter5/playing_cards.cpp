//
// Created by Matthew Wheeler on 21/10/2025.
//

#include "playing_cards.h"

namespace cards {
std::ostream& operator<<(std::ostream& os, const Card& card) {
    os << card.value().value() << " of " << static_cast<int>(card.suit());
    return os;
}

} // namespace cards