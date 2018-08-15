#include "pch.h"

void WriteFile(std::ofstream& file);

int main()
{
	try
	{
		std::string fileName("write_source.txt");
		std::ofstream file(fileName, std::ios::out);
		if (file.fail())
			throw std::runtime_error("Unable to open file");
		WriteFile(file);
		WriteFile(file);
		WriteFile(file);

		file.close();

		file.open(fileName, std::ios::app);
		if (file.fail())
			throw std::runtime_error("Unable to open file");

		WriteFile(file);

		file.close();
	}
	catch (const std::exception& e)
	{
		std::cout << "Writing error: " << e.what() << std::endl;
	}

	return 0;
}

void WriteFile(std::ofstream& file)
{
	file << "Just write to file" << std::endl;
}