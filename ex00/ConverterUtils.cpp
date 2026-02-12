#include "ScalarConverter.hpp"
#include <cstdlib>
#include <limits>
#include <cmath>
#include <iomanip>



bool ScalarConverter::_isChar(const std::string& s)
{
    return (s.length() == 1 && !std::isdigit(s[0]));
}

bool ScalarConverter::_isSpecialCase(const std::string& s)
{
    return (s == "nan" || s == "nanf" ||
            s == "+inf" || s == "-inf" ||
            s == "+inff" || s == "-inff");
}


bool ScalarConverter::_isInt(const std::string& s)
{
    size_t i = 0;

    if (s[i] == '+' || s[i] == '-')
        i++;

    if (i == s.length())
        return false;

    for (; i < s.length(); i++)
    {
        if (!std::isdigit(s[i]))
            return false;
    }
    return true;
}


bool ScalarConverter::_isDouble(const std::string& s)
{
    bool hasDot = false;
    size_t i = 0;

    if (s[i] == '+' || s[i] == '-')
        i++;

    if (i == s.length())
        return false;

    for (; i < s.length(); i++)
    {
        if (s[i] == '.')
        {
            if (hasDot)
                return false;
            hasDot = true;
        }
        else if (!std::isdigit(s[i]))
            return false;
    }
    return hasDot;
}


bool ScalarConverter::_isFloat(const std::string& s)
{
    if (s.length() < 2)
        return false;

    if (s[s.length() - 1] != 'f')
        return false;

    return _isDouble(s.substr(0, s.length() - 1));
}