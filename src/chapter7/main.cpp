//
// Created by Matthew Wheeler on 16/11/2025.
//

#include "smash.h"

int main() {
    const Dictionary keywords{
        {"char", "type for character representation which can be most efficiently "
                 "processed on the target system"},
        {"class", "user defined type with private members by default"},
        {"struct", "user defined type with public members by default"},
        {"vector", "sequential container supporting dynamic resizing"},
        {"template", "used for generic code"},
    };
    const Dictionary dictionary{
        {"assume", "take for granted, take to be the case"},
        {"harsh", "coarse, large-grained or rough to the touch"},
        {"table", "piece of furniture"},
        {"tease", "mock, make fun of"},
        {"torch", "lit stick carried in one's hand"},
    };
    simple_answer_smash(keywords, dictionary);
}
