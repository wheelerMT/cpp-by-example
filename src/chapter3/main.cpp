//
// Created by Matthew Wheeler on 17/10/2025.
//

#include <assert.h>
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
    std::cout << std::format("The number was {:0>5}\n", number);
}

constexpr bool is_prime(const int n) {
    if (n == 2 || n == 3) {
        return true;
    }

    if (n <= 1 || n % 2 == 0 || n % 3 == 0) {
        return false;
    }

    for (int i = 5; i * i < n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int get_random_prime() {
    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<int> dist{1, 99999};

    int n{};
    while (!is_prime(n)) {
        n = dist(engine);
    }
    return n;
}
std::string check_digits(int number, int guess) {
    auto ns = std::format("{:0>5}", number);
    const auto gs = std::format("{:0>5}", guess);
    std::string matches(5, '.');
    for (size_t i = 0, stop = gs.length(); i < stop; ++i) {
        if (const char guess_char = gs[i]; i < ns.length() && guess_char == ns[i]) {
            matches[i] = '*';
            ns[i] = '*';
        }
    }
    for (size_t i = 0, stop = gs.length(); i < stop; ++i) {
        if (const char guess_char = gs[i]; i < ns.length() && matches[i] != '*') {
            if (const size_t idx = ns.find(guess_char, 0); idx != std::string::npos) {
                matches[i] = '^';
                ns[idx] = '^';
            }
        }
    }

    return matches;
}
void check_properties() {
    assert(check_digits(12347, 23471) == "^^^^^");
    static_assert(is_prime(2));
}

int main() {
    check_properties();
    auto make_message = [](int number, int guess) {
        return std::format("{}\n", check_digits(number, guess));
    };
    guess_number(get_random_prime(), make_message);
}