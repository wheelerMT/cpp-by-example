//
// Created by Matthew Wheeler on 16/11/2025.
//

#include "smash.h"

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