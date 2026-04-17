#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "===== BASIC TEST =====" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "meta type: " << meta->getType() << std::endl;
	std::cout << "j type: " << j->getType() << std::endl;
	std::cout << "i type: " << i->getType() << std::endl;

	meta->makeSound();
	j->makeSound();
	i->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << "\n===== WRONG TEST =====" << std::endl;
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << "wrongMeta type: " << wrongMeta->getType() << std::endl;
	std::cout << "wrongCat type: " << wrongCat->getType() << std::endl;

	wrongMeta->makeSound();
	wrongCat->makeSound();

	delete wrongMeta;
	delete wrongCat;

	std::cout << "\n===== DIRECT OBJECT TEST =====" << std::endl;
	Dog dog;
	Cat cat;
	WrongCat badCat;

	std::cout << dog.getType() << ": ";
	dog.makeSound();

	std::cout << cat.getType() << ": ";
	cat.makeSound();

	std::cout << badCat.getType() << ": ";
	badCat.makeSound();

	std::cout << "\n===== COPY TEST =====" << std::endl;
	Dog dog1;
	Dog dog2(dog1);
	Cat cat1;
	Cat cat2;
	cat2 = cat1;

	std::cout << dog1.getType() << ": ";
	dog1.makeSound();
	std::cout << dog2.getType() << ": ";
	dog2.makeSound();
	std::cout << cat1.getType() << ": ";
	cat1.makeSound();
	std::cout << cat2.getType() << ": ";
	cat2.makeSound();

	std::cout << "\n===== ARRAY TEST =====" << std::endl;
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

	return 0;
}