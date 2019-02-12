#include "pch.h"
#include "Employee.h"
#include "Manager.h"

void _tmain(int argc, TCHAR* argv[])
{
	try
	{
		std::list<Employee*> group;

		Employee eml(_T("Servant"));
		Manager* mgr = new Manager(_T("Master"), 10);

		group.push_back(&eml);
		group.push_back(mgr);

		std::for_each(group.begin(), group.end(), [](Employee* const eml) -> void { eml->Print(); });

		group.clear();
		delete mgr;
	}
	catch (const std::exception& e)
	{
		_tcerr << "Error occurred: " << e.what() << std::endl;
	}
}