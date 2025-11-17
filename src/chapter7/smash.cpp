//
// Created by Matthew Wheeler on 16/11/2025.
//

#include "smash.h"

#include <iostream>
#include <ranges>

std::pair<std::string, int> find_overlapping_word(const std::string& word,
                                                  const Dictionary& dictionary) {
    size_t offset{1};
    while (offset < word.size()) {
        auto stem = word.substr(offset);
        for (const auto& k : dictionary | std::views::keys) {
            if (auto key_stem = k.substr(0, stem.size()); key_stem == stem) {
                return {k, offset};
            }
        }
        ++offset;
    }
    return {"", -1};
}
void simple_answer_smash(const Dictionary& keywords, const Dictionary& dictionary) {
    for (const auto& [word, definition] : keywords) {
        auto [second_word, offset] = find_overlapping_word(word, dictionary);

        if (offset == -1) {
            std::println("Not match for {}", word);
            continue;
        }

        std::string second_definition = dictionary.at(second_word);
        std::print("{}\nAND\n{}\n", definition, second_definition);

        std::string answer = word.substr(0, offset) + second_word;
        std::string response;
        std::getline(std::cin, response);
        if (response == answer) {
            std::println("CORRECT! ! ! ! !");
        } else {
            std::println("{}", answer);
        }
        std::println("{} {}", word, second_word);
    }
}