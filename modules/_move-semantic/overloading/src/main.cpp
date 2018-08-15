#include "pch.h"

std::map<int, std::string> ids({ { 1, "Vasya" },{ 2, "Petya" },{ 3, "Vova" } });
std::unordered_set<std::string> names;

template <typename T>
void LogAndAdd(T&& name) {
	LogAndAddImpl(std::forward<T>(name), std::is_integral<
		typename std::remove_reference<T>::type >());
}

template <typename T>
void LogAndAddImpl(T&& nameId, std::true_type) {
	std::cout << "true" << std::endl;
	LogAndAdd(ids.at(nameId));
}

template <typename T>
void LogAndAddImpl(T&& name, std::false_type) {
	std::cout << "false" << std::endl;
	names.emplace(std::forward<T>(name));
}

int main(int argc, char* argv[])
{
	try
	{
		LogAndAdd("Kolya");
		LogAndAdd(1);
		LogAndAdd(11);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error occurred: " << e.what() << std::endl;
	}

	return EXIT_SUCCESS;
}