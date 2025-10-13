//
// Created by Matthew Wheeler on 13/10/2025.
//

#ifndef CPP4F_BLACKSCHOLES_H
#define CPP4F_BLACKSCHOLES_H
#include <array>

namespace cpp4f {
enum class PayoffType { Call = 1, Put = -1 };

class BlackScholes {
public:
    // default dividend
    BlackScholes(double strike, double spot, double time_to_exp, PayoffType payoff_type,
                 double rate, double div = 0.0);

    double operator()(double vol);

private:
    std::array<double, 2> compute_norm_args(double vol);

    double m_strike, m_spot, m_time_to_exp;
    PayoffType m_payoff_type;
    double m_rate, m_div;
};
} // namespace cpp4f

#endif // CPP4F_BLACKSCHOLES_H
