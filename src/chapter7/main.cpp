//
// Created by Matthew Wheeler on 16/11/2025.
//

#include <iostream>
#include <map>

void warm_up() {
    std::map<std::string, std::string> dictionary;
    dictionary["assume"] = "take for granted, take to be the case";
    std::string new_value = dictionary["fictional"];
    for (const auto& [key, value] : dictionary) {
        std::println("{} : {}", key, value);
    }
}

int main() {
    warm_up();
}
