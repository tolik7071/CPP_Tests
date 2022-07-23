#include "UserDefinedLiterals.h"    
#include <numbers>
#include <iostream>

// used as conversion from degrees (input param) to radians (returned output)
constexpr long double operator"" _deg_to_rad(long double deg)
{
    long double radians = deg * std::numbers::pi_v<long double> / 180;
    return radians;
}

void UserDefinedLiterals::LiteralsTest()
{
    long double x_rad = 90.0_deg_to_rad;
    std::cout << std::fixed << x_rad << std::endl;
}
