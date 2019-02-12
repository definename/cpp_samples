#include "pch.h"

class BB8
{
public:
	BB8()
	{
		_tcout << "BB8 has been created" << std::endl;
	}
	~BB8()
	{
		_tcout << "BB8 has been destroyed" << std::endl;
	}
};

void _tmain(int argc, TCHAR* argv[])
{
	try
	{
		std::auto_ptr<BB8> bb8;
		bb8.reset(new BB8());
		std::auto_ptr<BB8> bb81(bb8);
		if (!bb8.get())
			_tcout << _T("bb8 ptr is not initialized") << std::endl;

		std::auto_ptr<BB8> bb82(bb81);
		if (!bb81.get())
			_tcout << _T("bb81 ptr is not initialized") << std::endl;

		std::auto_ptr<BB8> bb83(bb82);
		if (!bb82.get())
			_tcout << _T("bb82 ptr is not initialized") << std::endl;
	}
	catch (const std::exception& e)
	{
		_tcerr << _T("Error corrupted: ") << e.what() << std::endl;
	}
}