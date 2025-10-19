#include <chrono>
#include <ostream>

void duration_to_end_of_year() {
    const std::chrono::time_point now = std::chrono::system_clock::now();
    constexpr auto year = 2025;
    constexpr auto new_years_eve = std::chrono::year_month_day(
        std::chrono::year(year), std::chrono::month(12), std::chrono::day(31));
    constexpr auto event = std::chrono::sys_days(new_years_eve);
    std::chrono::duration duration = event - now;
    std::println("Duration to event: {}", duration);
}

int main() {
    duration_to_end_of_year();
}
