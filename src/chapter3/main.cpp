//
// Created by Matthew Wheeler on 17/10/2025.
//

#include <functional>
#include <iostream>
#include <ostream>
#include <random>

unsigned int input() {
    unsigned int number;
    while (!(std::cin >> number)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please enter a number.\n";
    }

    return number;
}

std::optional<int> read_number(std::istream& in) {
    if (int result{}; in >> result) {
        return result;
    }
    in.clear();
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return {};
}

void guess_number(const int number,
                  const std::function<std::string(int, int)>& message) {
    std::cout << "Guess the number.\n>";
    std::optional<int> guess;
    while ((guess = read_number(std::cin))) {
        if (guess.value() == number) {
            std::cout << "Well done!\n";
            return;
        }
        std::cout << message(number, guess.value());
        std::cout << '>';
    }
    std::cout << std::format("The number was {}\n", number);
}

int get_random_number() {
    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<int> dist(1, 100);
    return dist(engine);
}

int main() {
    auto make_message = [](int number, int guess) {
        return std::format("Your guess was too {}\n",
                           (guess < number ? "small" : "big"));
    };
    guess_number(get_random_number(), make_message);
}