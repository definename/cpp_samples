#include "pch.h"

void DoProcess(const std::string& lvalue) {
	std::cout << "lvalue" << std::endl;
}
void DoProcess(std::string&& rvalue) {
	std::cout << "rvalue" << std::endl;
}

template<typename T>
void Process(T&& param) {
	DoProcess(std::forward<T>(param));
}

template<typename T>
std::string DoItAlwaysWithForward(T&& data) {
	return std::forward<T>(data);
}

std::string UseMoveToReturnRValue(std::string&& name) {
	name += " Name";
	return std::move(name);
}

std::string DoNotUseMoveToReturnLocalValueBecauseOfRVO() {
	std::string name = "Name";
	return name;
}

int main(int argc, char* argv[])
{
	try
	{
		{
			std::string val;
			Process(val);
			Process(std::move(val));
		}

		std::string data = "data";
		std::cout << "was copied: " << DoItAlwaysWithForward(data) << std::endl;
		std::cout << "was moved: " << DoItAlwaysWithForward(std::move(data)) << std::endl;

		std::cout << UseMoveToReturnRValue("My name is") << std::endl;

		std::cout << DoNotUseMoveToReturnLocalValueBecauseOfRVO() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error occurred: " << e.what() << std::endl;
	}

	return EXIT_SUCCESS;
}