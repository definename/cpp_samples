#include "pch.h"
#include "ArchersCreator.h"
#include "CavalryCreator.h"
#include "InfantryCreator.h"

void _tmain(int argc, TCHAR* argv[])
{
	try
	{
		typedef IWarrior* IWarriorPtr;
		std::vector<IWarriorPtr> box;

		ArchersCreator aCreator;
		CavalryCreator cCreator;
		InfantryCreator iCreator;

		box.push_back(aCreator.CreateWarrior());
		box.push_back(cCreator.CreateWarrior());
		box.push_back(iCreator.CreateWarrior());

		for (const IWarriorPtr &val : box)
		{
			val->Info();
		}
	}
	catch (const std::exception& e)
	{
		_tcerr << "Error occurred: " << e.what() << std::endl;
	}
}