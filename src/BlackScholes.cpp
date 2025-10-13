//
// Created by Matthew Wheeler on 13/10/2025.
//

#include "BlackScholes.h"

#include <algorithm>
#include <cmath>
#include <numbers>

namespace cpp4f {

BlackScholes::BlackScholes(double strike, double spot, double time_to_exp,
                           PayoffType payoff_type, double rate, double div)
    : m_strike{strike}
    , m_spot{spot}
    , m_time_to_exp{time_to_exp}
    , m_payoff_type{payoff_type}
    , m_rate{rate}
    , m_div{div} {}

double BlackScholes::operator()(double vol) {
    using std::exp;
    const int phi = static_cast<int>(m_payoff_type);

    if (m_time_to_exp > 0.0) {
        const auto norm_args = compute_norm_args(vol);
        const double d1 = norm_args[0];
        const double d2 = norm_args[1];

        auto norm_cdf = [](const double x) {
            return (1.0 + std::erf(x / std::numbers::sqrt2)) / 2.0;
        };

        const double nd_1 = norm_cdf(phi * d1);
        const double nd_2 = norm_cdf(phi * d2);
        const double disc_fctr = exp(-m_rate * m_time_to_exp);

        return phi * (m_spot * exp(-m_div * m_time_to_exp) * nd_1 -
                      disc_fctr * m_strike * nd_2);
    }

    return std::max(phi * (m_spot - m_strike), 0.0);
}

} // namespace cpp4f