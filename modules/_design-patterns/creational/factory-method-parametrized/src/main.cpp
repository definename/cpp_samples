#include "pch.h"
#include "Warrior.h"

void main(int argc, char* argv[])
{
	try
	{
		std::vector<types::WarriorPtr> box;

		box.push_back(Warrior::CreateWarrior(Warrior::Type::ARCHER));
		box.push_back(Warrior::CreateWarrior(Warrior::Type::CAVALRY));
		box.push_back(Warrior::CreateWarrior(Warrior::Type::INFANTRY));

		for (const auto &val : box) {
			val->Info();
		}
	}
	catch (const std::exception& e)
	{
		_tcerr << "Error occurred: " << e.what() << std::endl;
	}
}