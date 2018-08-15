#include "pch.h"

void ResetPosition(std::fstream& file);
void Read1(std::fstream& file);
void Read2(std::fstream& file);

int main()
{
	try
	{
		std::fstream file("read_source.txt");

		if (file.fail())
			throw std::runtime_error("Unable to open file");

		Read1(file);
		ResetPosition(file);
		Read2(file);
	}
	catch (const std::exception& e)
	{
		std::cout << "Reading error: " << e.what() << std::endl;
		exit(1);
	}

	return 0;
}

void Read1(std::fstream& file)
{
	std::cout << "\tRead1 example" << std::endl;
	std::string text;
	while (std::getline(file, text))
		std::cout << text << std::endl;
}

void Read2(std::fstream& file)
{
	std::cout << "\tRead2 example" << std::endl;
	std::string text;
	while (file >> text)
		std::cout << text << std::endl;
}

void ResetPosition(std::fstream& file)
{
	if (file.eof())
	{
		file.clear();
		file.seekg(0, file.beg);
	}
}