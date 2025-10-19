#include <chrono>
#include <ostream>

void duration_to_end_of_year() {
    using namespace std::chrono;
    const time_point now = system_clock::now();
    const auto ymd = year_month_day{floor<days>(now)};

    const auto this_year = ymd.year();
    const auto new_years_eve = this_year / December / 31;

    const auto event = sys_days(new_years_eve);
    const duration dur = event - now;

    std::println("Duration to event: {}", duration_cast<days>(dur));
}

int main() {
    duration_to_end_of_year();
}
