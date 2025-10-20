#include <__thread/this_thread.h>
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

void pay_day() {
    using namespace std::chrono;

    const time_point now = system_clock::now();
    const auto ymd = year_month_day{floor<days>(now)};
    const auto pay_day = ymd.year() / ymd.month() / Friday[last];

    const auto event = sys_days(pay_day);
    const duration dur = event - now;

    std::println("You have {} until pay day", duration_cast<days>(dur));
}

constexpr std::chrono::system_clock::duration
countdown(const std::chrono::system_clock::time_point start) {
    using namespace std::chrono;

    const auto days_only = floor<days>(start);
    const auto ymd = year_month_day{days_only};
    const auto this_year = ymd.year();
    const auto new_years_eve = this_year / December / last;

    const auto event = sys_days(new_years_eve);
    return event - start;
}

void check_properties() {
    using namespace std::chrono;
    constexpr auto new_years_eve = 2025y / December / last;
    constexpr auto one_day_away = sys_days{new_years_eve} - 24h;
    constexpr auto result = countdown(one_day_away);
    static_assert(duration_cast<days>(result) == days{1});
}

int main() {
    duration_to_end_of_year();
    pay_day();
    check_properties();

    using namespace std::chrono;
    for (int i = 0; i < 5; ++i) {
        std::this_thread::sleep_for(1000ms);
        auto dur = countdown(system_clock::now());
        std::println("{} until event", duration_cast<seconds>(dur));
    }
}
