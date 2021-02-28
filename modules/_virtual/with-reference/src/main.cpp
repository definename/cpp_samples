#include "pch.h"

class Pet {
public:
	Pet() = default;
	virtual ~Pet() = default;

public:
	virtual void Noise() = 0;
};

class Dog :public Pet {
public:
	Dog() = default;
	~Dog() = default;
	void Noise() override {
		std::cout << "Growl" << std::endl;
	}
};

class Cat : public Pet {
public:
	Cat() = default;
	~Cat() = default;

public:
	void Noise() override {
		std::cout << "Mew" << std::endl;
	}
};

void main(int argc, char* argv[])
{
	try
	{
		logger::InitializeLog("console");

		// Checks how polymorphism works with references;
		{
			Pet* ppet = new Dog;
			Pet& pet = *ppet;
			pet.Noise();

			auto testNoise = [](Pet& pet) {
				pet.Noise();
			};
			testNoise(*ppet);
		}

		logger::UninitializeLog();
	}
	catch (const spdlog::spdlog_ex& e)
	{
		std::cerr << "Logger error occurred: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		logger::log->error("Error occurred: {}", e.what());
		logger::UninitializeLog();
	}

}