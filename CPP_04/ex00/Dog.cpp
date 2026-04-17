#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog default constructor called " << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
    std::cout << "Dog copy constructor called " << std::endl; 
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other)
	    Animal::operator=(other);
	return *this;
        
}
Dog::~Dog()
{
    std::cout << "Dog default destructor called " << std::endl; 
}

void Dog::makeSound() const
{
	std::cout << "Waf Waf" << std::endl;
}