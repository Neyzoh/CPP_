#include <iostream>
#include <string>

int main(void)
{
    std::string myVar = "HI THIS IS BRAIN";
    std::string *stringPTR = &myVar;
    std::string &stringREF = myVar;

    std::cout << "Adress of myVar is : " << std::endl;
    std::cout << &myVar << std::endl;

    std::cout << "Adress of stringPTR is :" << std::endl;
    std::cout << stringPTR << std::endl;

    std::cout << "Adress of stringREF is :" << std::endl;
    std::cout << &stringREF << std::endl;

    std::cout << "Value of myVar is : " << std::endl;
    std::cout << myVar << std::endl;

    std::cout << "Value of stringPTR is :" << std::endl;
    std::cout << *stringPTR << std::endl;

    std::cout << "Value of stringREF is :" << std::endl;
    std::cout << stringREF << std::endl;

    return(0);
}