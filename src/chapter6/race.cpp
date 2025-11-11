//
// Created by Matthew Wheeler on 29/10/2025.
//

#include "race.h"

#include <iostream>

namespace Race {

void draw_blobs(const std::vector<StepperBlob>& blobs) {
    constexpr int race_height = 8;
    for (int y = race_height; y >= 0; --y) {
        constexpr int bag_height = 3;
        std::string output = y >= bag_height ? "  " : "| ";
        for (const auto& blob : blobs) {
            if (blob.total_steps() >= y) {
                output += "* ";
            } else {
                output += "  ";
            }
        }
        output += y >= bag_height ? ' ' : '|';
        std::cout << output << '\n';
    }
    constexpr int edges = 3;
    std::cout << std::string(blobs.size() * 2 + edges, '-') << '\n';
}
} // namespace Race