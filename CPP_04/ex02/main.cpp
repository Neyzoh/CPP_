#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "----- Polymorphism test -----" << std::endl;

	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << ": ";
	j->makeSound();
	std::cout << i->getType() << ": ";
	i->makeSound();

	delete j;
	delete i;

	std::cout << "\n----- Array test -----" << std::endl;
	Animal* animals[4];

	for (int k = 0; k < 2; k++)
		animals[k] = new Dog();
	for (int k = 2; k < 4; k++)
		animals[k] = new Cat();

	for (int k = 0; k < 4; k++)
	{
		std::cout << animals[k]->getType() << ": ";
		animals[k]->makeSound();
	}

	for (int k = 0; k < 4; k++)
		delete animals[k];

	std::cout << "\n----- Deep copy test -----" << std::endl;
	Cat original;
	original.setIdea(0, "I want fish");

	Cat copy(original);

	std::cout << "Original idea: " << original.getIdea(0) << std::endl;
	std::cout << "Copy idea: " << copy.getIdea(0) << std::endl;

	original.setIdea(0, "I want sleep");

	std::cout << "After changing original:" << std::endl;
	std::cout << "Original idea: " << original.getIdea(0) << std::endl;
	std::cout << "Copy idea: " << copy.getIdea(0) << std::endl;

	std::cout << "\n----- Assignment test -----" << std::endl;
	Dog a;
	Dog b;

	a.setIdea(0, "Catch the ball");
	b = a;

	std::cout << "A idea: " << a.getIdea(0) << std::endl;
	std::cout << "B idea: " << b.getIdea(0) << std::endl;

	a.setIdea(0, "Sleep on the couch");

	std::cout << "After changing A:" << std::endl;
	std::cout << "A idea: " << a.getIdea(0) << std::endl;
	std::cout << "B idea: " << b.getIdea(0) << std::endl;

	// Animal test; // This must not compile: Animal is abstract

	return 0;
}