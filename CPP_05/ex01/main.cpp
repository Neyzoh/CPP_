#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat b1("Alice", 10);
        Bureaucrat b2("Bob", 100);

        Form f1("Tax Form", 20, 50);
        Form f2("Secret Form", 5, 10);

        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;

        b1.signForm(f1);

        b2.signForm(f2);

        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}