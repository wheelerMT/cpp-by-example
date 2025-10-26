#include "playing_cards.h"
using namespace cards;

int main() {
    const Card card{FaceValue(11), Suit::Clubs};
    std::cout << card << '\n';
}