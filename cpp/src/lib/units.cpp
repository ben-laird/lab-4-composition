#include <vector>
#include <numeric>

#include "errors.h"

#include "units.h"

bool Compare(bool a, bool b)
{
    return a && b;
};

bool Unit::match(Unit &rhs)
{
    if (units.size() != rhs.units.size())
    {
        return false;
    }

    std::vector<bool> comparisons;

    for (auto component : units)
    {

        auto rhs_component_iter = rhs.units.find(component.first);
        auto outside = rhs.units.end();

        if (rhs_component_iter == outside)
        {
            comparisons.push_back(false);
            continue;
        }

        bool res = component == *rhs_component_iter;

        comparisons.push_back(res);
    }

    return std::accumulate(comparisons.begin(), comparisons.end(), true, Compare);
}

bool operator==(Unit &lhs, Unit &rhs)
{
    return lhs.match(rhs) && lhs.value == rhs.value;
}

bool operator!=(Unit &lhs, Unit &rhs)
{
    return !(lhs == rhs);
}

Unit operator+(Unit lhs, Unit rhs)
{
    if (!lhs.match(rhs))
    {
        throw Error("Units do not match!");
    }

    return Unit{lhs.value + rhs.value, lhs.units};
}

Unit operator-(Unit lhs, Unit rhs)
{
    if (!lhs.match(rhs))
    {
        throw Error("Units do not match!");
    }

    return Unit{lhs.value - rhs.value, lhs.units};
}

Unit operator*(Unit lhs, Unit rhs)
{
    return Unit{lhs.value * rhs.value, lhs.merge_multiply(rhs)};
}
Unit operator*(float scalar, Unit unit)
{
    unit.value = unit.value * scalar;

    return unit;
}
Unit operator*(Unit unit, float scalar)
{
    return scalar * unit;
}

Unit Unit::operator/(Unit rhs)
{
    return Unit{value / rhs.value, merge_divide(rhs)};
}
Unit Unit::operator/(float scalar)
{
    value = value / scalar;

    return *this;
}

std::unordered_map<std::string, int> Unit::merge_multiply(Unit &rhs)
{
    std::unordered_map<std::string, int> new_units = units;

    for (auto rhs_component : rhs.units)
    {
        auto component_iter = new_units.find(rhs_component.first);
        auto outside = rhs.units.end();

        if (component_iter == outside)
        {
            new_units.emplace(rhs_component);
            continue;
        }

        int new_degree = component_iter->second + rhs_component.second;

        new_units.insert_or_assign(rhs_component.first, new_degree);
    }

    return new_units;
}

std::unordered_map<std::string, int> Unit::merge_divide(Unit &rhs)
{
    std::unordered_map<std::string, int> new_units = units;

    for (auto rhs_component : rhs.units)
    {
        auto component_iter = new_units.find(rhs_component.first);
        auto outside = rhs.units.end();

        if (component_iter == outside)
        {
            new_units.emplace(rhs_component.first, -rhs_component.second);
            continue;
        }

        int new_degree = component_iter->second - rhs_component.second;

        new_units.insert_or_assign(rhs_component.first, new_degree);
    }

    return new_units;
}
