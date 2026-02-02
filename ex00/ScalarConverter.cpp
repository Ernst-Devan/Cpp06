#include "ScalarConverter.hpp"
#include "Conversion.hpp"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>

ScalarConverter::ScalarConverter() {};
ScalarConverter::ScalarConverter(ScalarConverter const& s) {(void)s; return;};
ScalarConverter& ScalarConverter::operator=(ScalarConverter const& s) {(void)s; return *this;};
ScalarConverter::~ScalarConverter() {};

void convert_to_char(Conversion& l)
{
    if (l.getType() == INT)
    {
        l.setC(static_cast<char>(l.getI()));
    }
    if (l.getType() == FLOAT)
    {
        l.setC(static_cast<char>(l.getF()));
    }
    if (l.getType() == DOUBLE)
    {
        l.setC(static_cast<char>(l.getD()));
    }
}

void convert_to_int(Conversion& l)
{

    if (l.getType() == CHAR)
    {
        l.setI(static_cast<int>(l.getC()));
    }
    if (l.getType() == FLOAT)
    {
        l.setI(static_cast<int>(l.getF()));
    }
    if (l.getType() == DOUBLE)
    {
        l.setI(static_cast<int>(l.getD()));
    }
}

void convert_to_float(Conversion& l)
{
    if (l.getType() == CHAR)
    {
        l.setF(static_cast<float>(l.getC()));
    }
    if (l.getType() == INT)
    {
        l.setF(static_cast<float>(l.getI()));
    }
    if (l.getType() == DOUBLE)
        l.setF(static_cast<float>(l.getD()));
}

void convert_to_double(Conversion& l)
{
    if (l.getType() == CHAR)
    {
        l.setD(static_cast<double>(l.getC()));
    }
    if (l.getType() == INT)
    {
        l.setD(static_cast<double>(l.getI()));
    }
    if (l.getType() == FLOAT)
        l.setD(static_cast<double>(l.getF()));

}

int check_ascii_char(char c)
{
    if ((c >= 32 && c <= 47) || (c >= 58 && c <= 127))
            return 1;
    return (0);
}

int check_char(std::string value)
{
    if (value.length() == 1)
    {
        if (check_ascii_char(value[0]))
            return 1;
    }
    return (0);
}

int check_int(std::string value)
{
    if (value.length() == 1)
    {
        if (isdigit(value[0]))
            return (1);
    }
    else
    {
        if (!value.find_first_not_of("0123456789-"))
            return (0);
        for(size_t i = 1; i < value.length(); i++)
        {
            if (check_ascii_char(value[i]))
                return (0);
        }
    }
    return (1);
}

int check_float(std::string value)
{
    unsigned int dot = 0;

    if (!value.find_first_not_of("0123456789-"))
        return (0);
    if (value[value.length() - 1] != 'f')
        return (0);
    for(size_t i = 1; i < value.length() - 1; i++)
    {
        if (check_ascii_char(value[i]))
        {
            if (value[i] == '.')
            {
                if (!isdigit(value[i + 1]))
                    return (0);
                dot++;
            }
            else
                return (0);
        }
    }
    if (dot == 1)
        return (1);
    return (0);
}

int check_double(std::string value)
{
    unsigned int dot = 0;

    if (!value.find_first_not_of("0123456789-"))
        return (0);
    for(size_t i = 1; i < value.length(); i++)
    {
        if (check_ascii_char(value[i]))
        {
            if (value[i] == '.')
            {
                if (!isdigit(value[i + 1]))
                    return (0);
                dot++;
            }
            else
                return (0);
        }
    }
    if (dot == 1)
        return (1);
    return (0);
}

void detect_type(std::string value, Conversion& l)
{
    if (value == "nan")
        l.setType(DOUBLE);
    else if (value == "+inf")
        l.setType(DOUBLE);
    else if (value == "-inf")
        l.setType(DOUBLE);
    else if (value == "nanf")
        l.setType(FLOAT);
    else if (value == "+inff")
        l.setType(FLOAT);
    else if (value == "-inff")
        l.setType(FLOAT);
    else if (check_char(value))
        l.setType(CHAR);
    else if (check_int(value))
        l.setType(INT);
    else if (check_float(value))
        l.setType(FLOAT);
    else if (check_double(value))
        l.setType(DOUBLE);
}

void display_type_find(int type)
{
    std::cout << "Type find: ";
    if (type == CHAR)
        std::cout << "CHAR" << std::endl;
    if (type == INT)
        std::cout << "INT" << std::endl;
    if (type == FLOAT)
        std::cout << "FLOAT" << std::endl;
    if (type == DOUBLE)
        std::cout << "DOUBLE" << std::endl;
}

void    convert_initial(std::string value, Conversion& l)
{
    if (l.getType() == CHAR)
    {
        l.setC(value[0]);
    }
    if (l.getType() == INT)
    {
        l.setI(std::atoi(value.c_str()));
    }
    if (l.getType() == FLOAT)
    {
        l.setF(std::atof(value.c_str()));
    }
    if (l.getType() == DOUBLE)
    {
        l.setD(std::atof(value.c_str()));
    }
}

void    manage_conversion(std::string value, Conversion& l)
{
    convert_initial(value, l);
    convert_to_char(l);
    convert_to_int(l);
    convert_to_float(l);
    convert_to_double(l);
}

void display_conversion(Conversion& list)
{
    if (!isascii(list.getC()) || list.getI() > 128 || list.getI() < 0)
    {
        std::cout << "char: impossible" << std::endl;
    }
    else if (!isprint(list.getC()))
    {
        std::cout << "char: Non displayable" << std::endl;
    }
    else
    {
        std::cout << "char: '" << list.getC() << "'" << std::endl;
    }

    if (std::isnan(list.getF()) || std::isinf(list.getF()))
    {
        std::cout << "int: impossible" << std::endl;
    }
    else 
    {
        std::cout << "int: " << list.getI() << std::endl;
    }
    
    std::cout << "float: " << list.getF() << "f" << std::endl;
    std::cout << "double: " << list.getD() << std::endl;
}

void ScalarConverter::convert(std::string value)
{
    Conversion list;
    
    if (value.length() == 0)
        return;


    detect_type(value, list);
    if (list.getType() == -1)
    {
        std::cout << "Value not valid" << std::endl;
        return;
    }

    manage_conversion(value, list);
    display_conversion(list);
}

