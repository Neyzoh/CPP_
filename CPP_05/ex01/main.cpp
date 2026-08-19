#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat b1("Alice", 10);
        Bureaucrat b2("Bob", 100);

        Form f1("Tax Form", 20, 50);     // grade to sign = 20
        Form f2("Secret Form", 5, 10);   // grade to sign = 5

        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;

        // b1 (grade 10) signe f1 (grade to sign 20) → OK (10 <= 20)
        b1.signForm(f1);

        // b2 (grade 100) essaie de signer f2 (grade to sign 5) → trop bas
        b2.signForm(f2);

        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}