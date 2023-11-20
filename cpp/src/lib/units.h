#pragma once

#include <string>
#include <unordered_map>

bool Compare(bool a, bool b);

class Unit
{
public:
    float value;
    std::unordered_map<std::string, int> units;

    bool match(Unit &rhs);

    friend bool operator==(Unit &lhs, Unit &rhs);

    friend bool operator!=(Unit &lhs, Unit &rhs);

    friend Unit operator+(Unit lhs, Unit rhs);

    friend Unit operator-(Unit lhs, Unit rhs);

    friend Unit operator*(Unit lhs, Unit rhs);
    friend Unit operator*(float scalar, Unit unit);
    friend Unit operator*(Unit unit, float scalar);

    Unit operator/(Unit rhs);
    Unit operator/(float scalar);

protected:
    std::unordered_map<std::string, int> merge_multiply(Unit &rhs);

    std::unordered_map<std::string, int> merge_divide(Unit &rhs);
};
