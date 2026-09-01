#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>

class ScalarConverter 
{
private:
    ScalarConverter();

    static bool isCharLiteral(const std::string& s);
    static bool isIntLiteral(const std::string& s);
    static bool isFloatLiteral(const std::string& s);
    static bool isDoubleLiteral(const std::string& s);

    static void printChar(double value);
    static void printInt(double value);
    static void printFloat(double value);
    static void printDouble(double value);

    static bool isDisplayableChar(int c);
    static bool isPseudoFloat(const std::string& s);
    static bool isPseudoDouble(const std::string& s);
public:
    static void convert(const std::string& literal);
};

#endif