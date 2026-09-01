#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate(void) 
{
    int r = std::rand() % 3;
    if (r == 0) return new A();
    if (r == 1) return new B();
    return new C();
}

void identify(Base* p) 
{
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    }
}

void identify(Base& p) 
{
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
        return;
    } catch (...) {}

    try {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return;
    } catch (...) {}

    try {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
        return;
    } catch (...) {}
}

int main() 
{
    std::srand(static_cast<unsigned int>(std::time(0)));

    for (int i = 0; i < 10; ++i) 
    {
        Base* ptr = generate();

        std::cout << "Test " << i << " (pointer): ";
        identify(ptr);

        std::cout << "Test " << i << " (reference): ";
        identify(*ptr);

        delete ptr;
    }

    return 0;
}