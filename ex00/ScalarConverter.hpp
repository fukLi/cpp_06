#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

class ScalarConverter
{
    private:
        static bool _findType(const std::string& str, double *d);
        static void _displayChar(double &d);
        static void _displayInt(double &d);
        static void _displayFloat(double &d);
        static void _displayDouble(double &d);
        static void _displaySpecialCase(const std::string& s);


        ///utils
        static bool _isChar(const std::string& s);
        static bool _isInt(const std::string& s);
        static bool _isFloat(const std::string& s);
        static bool _isDouble(const std::string& s);
        static bool _isSpecialCase(const std::string& s);

        //orthodox canonical form
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();


    public:
        static void convert(std::string const &str);
};

#endif

