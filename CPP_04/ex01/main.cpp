#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "----- Array test -----" << std::endl;
	Animal* animals[4];

	for (int i = 0; i < 2; i++)
		animals[i] = new Dog();
	for (int i = 2; i < 4; i++)
		animals[i] = new Cat();

	for (int i = 0; i < 4; i++)
	{
		std::cout << animals[i]->getType() << ": ";
		animals[i]->makeSound();
	}

	for (int i = 0; i < 4; i++)
		delete animals[i];

	std::cout << "\n----- Deep copy test -----" << std::endl;
	Cat original;
	original.setIdea(0, "I want fish");

	Cat copy(original);
	std::cout << "Original idea: " << original.getIdea(0) << std::endl;
	std::cout << "Copy idea: " << copy.getIdea(0) << std::endl;

	original.setIdea(0, "I want sleep");

	std::cout << "After change:" << std::endl;
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

	std::cout << "After change:" << std::endl;
	std::cout << "A idea: " << a.getIdea(0) << std::endl;
	std::cout << "B idea: " << b.getIdea(0) << std::endl;

	return 0;
}