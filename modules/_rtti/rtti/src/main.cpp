#include "pch.h"

class Pet {
public:
	Pet() = default;
	virtual ~Pet() = 0 {}
};

class Dog :public Pet {
public:
	Dog() = default;
	~Dog() = default;
	void Growl() {
		std::cout << "Dog" << std::endl;
	}
};
class Cat : public Pet {
public:
	Cat() = default;
	~Cat() = default;
	void Mew() {
		std::cout << "Cat" << std::endl;
	}
};

int main(int argc, char* argv[])
{
	// Downcast: from base to derived
	{
		Pet* ppet = nullptr;

		ppet = new Cat;
		if (Cat* pcat = dynamic_cast<Cat*>(ppet)) {
			pcat->Mew();
		}
		delete ppet;
		ppet = nullptr;

		ppet = new Dog;
		if (Dog* pcat = dynamic_cast<Dog*>(ppet)) {
			pcat->Growl();
		}

		try {
			Dog& dog3 = dynamic_cast<Dog&>(*ppet);
			dog3.Growl();

			Dog d;
			Pet* pet1 = &d;
			Dog& dog1 = dynamic_cast<Dog&>(*pet1);
			dog1.Growl();

			Pet& pet2 = d;
			Dog& dog2 = dynamic_cast<Dog&>(pet2);
			dog2.Growl();

			Cat& cat = dynamic_cast<Cat&>(*ppet); // bad_cast error
			cat.Mew();
		}
		catch (const std::bad_cast& e) {
			std::cout << e.what() << std::endl;
		}
	}

	// Upcast: from derived to base
	{
		Dog* pdog = new Dog;
		if (Pet* ppet = dynamic_cast<Pet*>(pdog)) {
			std::cout << "Casted" << std::endl;
		}
		// The same.
		Pet* ppet = pdog;
	}


	return EXIT_SUCCESS;
}