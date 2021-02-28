#include "pch.h"
#include "ClassA.h"
#include "ClassB.h"

_tostream& operator<<(_tostream& s, const IClass& c)
{
	return c.put(s);
}

void _tmain(int argc, TCHAR* argv[])
{
	try
	{
		typedef std::vector<IClass*> Box;
		Box box;
		ClassA* cA = new ClassA();
		ClassB* cB = new ClassB();

		box.push_back(cA);
		box.push_back(cB);

		for (const Box::value_type& val : box)
		{
			_tcout << *val << std::endl;
		}

		delete cB;
		delete cA;
	}
	catch (const std::exception& e)
	{
		_tcerr << "Error occurred: " << e.what() << std::endl;
	}
}