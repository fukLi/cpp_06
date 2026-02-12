#include "ScalarConverter.hpp"
#include <cstdlib>
#include <limits>
#include <cmath>
#include <iomanip>


void ScalarConverter::convert(std::string const &str)
{
    double d = 0.0;
    
    if (_isSpecialCase(str))
    {
        _displaySpecialCase(str);
        return;
    }

    if (!_findType(str, &d))
        return ;

    _displayChar(d);
    _displayInt(d);
    _displayFloat(d);
    _displayDouble(d);
}


void ScalarConverter::_displaySpecialCase(const std::string& s)
{
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";

    if (s == "nan" || s == "nanf")
    {
        std::cout << "float: nanf\n";
        std::cout << "double: nan\n";
    }
    else
    {
        if (s[0] == '-')
        {
            std::cout << "float: -inff\n";
            std::cout << "double: -inf\n";
        }
        else
        {
            std::cout << "float: +inff\n";
            std::cout << "double: +inf\n";
        }
    }
}


bool ScalarConverter::_findType(const std::string& str, double *d)
{
    if (_isChar(str))
        *d = static_cast<double>(str[0]);
    else if (_isInt(str) || _isDouble(str) || _isFloat(str))
        *d = std::atof(str.c_str());
    else
    {
        std::cout << "Invalid literal\n";
        return false;
    }
    return true;
}

void ScalarConverter::_displayChar(double &d)
{
    if (std::isnan(d) || d < 0 || d > 127)
        std::cout << "char: impossible\n";
    else if (!std::isprint(static_cast<char>(d)))
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: '" << static_cast<char>(d) << "'\n";
}

void ScalarConverter::_displayInt(double &d)
{
    if (std::isnan(d) || std::isinf(d) ||
        d > std::numeric_limits<int>::max() ||
        d < std::numeric_limits<int>::min())
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << static_cast<int>(d) << "\n";

}

void ScalarConverter::_displayFloat(double &d)
{
    float f = static_cast<float>(d);
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f\n";
}


void ScalarConverter::_displayDouble(double &d)
{
    std::cout << "double: " << d << "\n";
}



// Default constructor
ScalarConverter::ScalarConverter(void)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

// Copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
    return ;
}

// Assignment operator overload
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    std::cout << "Assignment operator called" << std::endl;
    if (this != &other)
    {
        //_name = other._name;
    }
    return (*this);
}

// Destructor
ScalarConverter::~ScalarConverter(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}