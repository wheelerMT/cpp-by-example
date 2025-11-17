//
// Created by Matthew Wheeler on 16/11/2025.
//

#ifndef CHAPTER7_SMASH_H
#define CHAPTER7_SMASH_H
#include <map>
#include <string>
#include <utility>
using Dictionary = std::map<std::string, std::string>;

std::pair<std::string, int> find_overlapping_word(const std::string& word,
                                                  const Dictionary& dictionary);

#endif // CHAPTER7_SMASH_H
