#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>

#define CHAR 0
#define INT 1
#define FLOAT 2
#define DOUBLE 3

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const& s);
        ScalarConverter& operator=(ScalarConverter const& s);
        ~ScalarConverter();
    public:
        static void convert(std::string value);
};

#endif
