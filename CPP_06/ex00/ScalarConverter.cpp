#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <cctype>
#include <iomanip>

ScalarConverter::ScalarConverter() 
{
}

bool ScalarConverter::isCharLiteral(const std::string& s) {
    if (s.size() != 3) return false;
    if (s[0] != '\'' || s[s.size() - 1] != '\'') return false;
    return true;
}

bool ScalarConverter::isIntLiteral(const std::string& s) 
{
    if (s.empty()) return false;
    size_t start = 0;
    if (s[0] == '+' || s[0] == '-') 
        start = 1;
    if (start == s.size()) 
        return false;
    for (size_t i = start; i < s.size(); ++i) 
    {
        if (!std::isdigit(static_cast<unsigned char>(s[i]))) 
            return false;
    }
    return true;
}

bool ScalarConverter::isPseudoFloat(const std::string& s) 
{
    return (s == "-inff" || s == "+inff" || s == "nanf");
}

bool ScalarConverter::isPseudoDouble(const std::string& s) 
{
    return (s == "-inf" || s == "+inf" || s == "nan");
}

bool ScalarConverter::isFloatLiteral(const std::string& s) 
{
    if (isPseudoFloat(s)) 
        return true;
    if (s.empty() || s[s.size() - 1] != 'f') 
        return false;

    std::string num = s.substr(0, s.size() - 1);
    if (num.empty()) 
        return false;

    size_t start = 0;
    if (num[0] == '+' || num[0] == '-') 
        start = 1;
    if (start == num.size()) 
        return false;

    bool hasDot = false;
    for (size_t i = start; i < num.size(); ++i) 
    {
        char c = num[i];
        if (c == '.') 
        {
            if (hasDot) return false;
            hasDot = true;
        } 
        else if (!std::isdigit(static_cast<unsigned char>(c))) 
            return false;
    }
    return hasDot;
}

bool ScalarConverter::isDoubleLiteral(const std::string& s) 
{
    if (isPseudoDouble(s)) 
        return true;
    if (s.empty()) 
        return false;

    size_t start = 0;
    if (s[0] == '+' || s[0] == '-') 
        start = 1;
    if (start == s.size()) 
        return false;

    bool hasDot = false;
    for (size_t i = start; i < s.size(); ++i) 
    {
        char c = s[i];
        if (c == '.') 
        {
            if (hasDot) 
                return false;
            hasDot = true;
        } 
        else if (!std::isdigit(static_cast<unsigned char>(c)))
            return false;
    }
    return hasDot;
}

bool ScalarConverter::isDisplayableChar(int c) 
{
    return (c >= 32 && c <= 126);
}

void ScalarConverter::printChar(double value) 
{
    std::cout << "char: ";
    if (std::isnan(value) || std::isinf(value)) 
    {
        std::cout << "impossible" << std::endl;
        return;
    }
    if (value < std::numeric_limits<char>::min() ||value > std::numeric_limits<char>::max()) 
    {
        std::cout << "impossible" << std::endl;
        return;
    }
    int c = static_cast<int>(value);
    if (!isDisplayableChar(c)) 
        std::cout << "Non displayable" << std::endl;
    else 
        std::cout << "'" << static_cast<char>(c) << "'" << std::endl;
}

void ScalarConverter::printInt(double value) 
{
    std::cout << "int: ";
    if (std::isnan(value) || std::isinf(value)) 
    {
        std::cout << "impossible" << std::endl;
        return;
    }
    if (value < std::numeric_limits<int>::min() ||value > std::numeric_limits<int>::max()) 
    {
        std::cout << "impossible" << std::endl;
        return;
    }
    std::cout << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printFloat(double value)
{
    std::cout << "float: ";

    if (std::isnan(value))
        std::cout << "nanf" << std::endl;
    else if (std::isinf(value))
    {
        if (value > 0)
            std::cout << "+inff" << std::endl;
        else
            std::cout << "-inff" << std::endl;
    }
    else
    {
        std::cout << std::fixed << std::setprecision(1)<< static_cast<float>(value) << "f" << std::endl;
        std::cout.unsetf(std::ios::floatfield);
    }
}

void ScalarConverter::printDouble(double value)
{
    std::cout << "double: ";

    if (std::isnan(value))
        std::cout << "nan" << std::endl;
    else if (std::isinf(value))
    {
        if (value > 0)
            std::cout << "+inf" << std::endl;
        else
            std::cout << "-inf" << std::endl;
    }
    else
    {
        std::cout << std::fixed << std::setprecision(1)<< value << std::endl;
        std::cout.unsetf(std::ios::floatfield);
    }
}
void ScalarConverter::convert(const std::string& literal) 
{
    double value = 0.0;

    if (isCharLiteral(literal)) 
    {
        char c = literal[1];
        value = static_cast<double>(c);
    } 
    else if (isIntLiteral(literal)) 
    {
        long v = std::strtol(literal.c_str(), 0, 10);
        value = static_cast<double>(v);
    } 
    else if (isFloatLiteral(literal)) 
    {
        if (isPseudoFloat(literal)) 
        {
            if (literal == "nanf") 
                value = std::numeric_limits<double>::quiet_NaN();
            else if (literal == "+inff") 
                value = std::numeric_limits<double>::infinity();
            else if (literal == "-inff") 
                value = -std::numeric_limits<double>::infinity();
        }
        else {
            std::string num = literal.substr(0, literal.size() - 1);
            float f = std::strtof(num.c_str(), 0);
            value = static_cast<double>(f);
        }
    } 
    else if (isDoubleLiteral(literal)) 
    {
        if (isPseudoDouble(literal)) 
        {
            if (literal == "nan")
                value = std::numeric_limits<double>::quiet_NaN();
            else if (literal == "+inf")
                value = std::numeric_limits<double>::infinity();
            else if (literal == "-inf")
                value = -std::numeric_limits<double>::infinity();
        } 
        else 
            value = std::strtod(literal.c_str(), 0);
    } else 
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}