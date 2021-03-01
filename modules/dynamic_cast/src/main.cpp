#include <iostream>
#include <string>
#include <memory>

class Pet {
public:
	virtual ~Pet() = 0;
};

Pet::~Pet() { }

class Dog : public Pet {
public:
	void Growl() const {
		std::cout << "Dog" << std::endl;
	}
};

class Cat : public Pet {
public:
	void Mew() const {
		std::cout << "Cat" << std::endl;
	}
};

int main(int argc, char* argv[])
{
	// Downcast: from base to derived
	{
		Pet* pet_cat = new Cat;
		if (Cat* pcat = dynamic_cast<Cat*>(pet_cat)) {
			pcat->Mew();
		}
		delete pet_cat;

		Pet* pet_dog = new Dog;
		if (Dog* pdog = dynamic_cast<Dog*>(pet_dog)) {
			pdog->Growl();
		}
		delete pet_dog;

		try {
			std::shared_ptr<Pet> pet_dog(new Dog);
			Dog& dog3 = dynamic_cast<Dog&>(*pet_dog);
			dog3.Growl();

			Dog d;
			Pet* pet_ptr = &d;
			Dog& dog1 = dynamic_cast<Dog&>(*pet_ptr);
			dog1.Growl();

			Pet& pet_ref = d;
			Dog& dog2 = dynamic_cast<Dog&>(pet_ref);
			dog2.Growl();

			// bad_cast error Dog is not casted to Cat
			Cat& cat = dynamic_cast<Cat&>(*pet_dog);
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
		delete pdog;
	}
	return EXIT_SUCCESS;
}