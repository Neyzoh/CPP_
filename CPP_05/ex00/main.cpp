#include <iostream>
#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b1("Alice", 1);
        std::cout << b1 << std::endl;

        b1.incrementGrade();
    } catch (const std::exception& e) 
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b2("Bob", 150);
        std::cout << b2 << std::endl;

        b2.decrementGrade(); 
    } catch (const std::exception& e) 
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b3("Charlie", 3);
        std::cout << b3 << std::endl;

        b3.incrementGrade();
        std::cout << b3 << std::endl;

        b3.decrementGrade(); 
        std::cout << b3 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b4("InvalidHigh", 0); 
        std::cout << b4 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b5("InvalidLow", 151); 
        std::cout << b5 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}