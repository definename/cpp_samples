#include "pch.h"
#include "DirectorImpl.h"

void _tmain(int argc, TCHAR* argv[])
{
	try
	{
		DirectorImpl* director = new DirectorImpl();
		director->CreateWidgets();

		delete director;
	}
	catch (const std::exception& e)
	{
		_tcerr << "Error occurred: " << e.what() << std::endl;
	}
}