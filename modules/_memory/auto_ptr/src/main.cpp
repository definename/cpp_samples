#include "pch.h"

namespace starwars
{

class BB8
{
	//
	// Construction and destruction.
	//
public:
	//! Constructor.
	explicit BB8(const _tstring name = _T("BB8"))
		: name_(name)
	{
		_tcout << "BB8 has been created" << std::endl;
	}
	//! Destructor.
	~BB8()
	{
		_tcout << "BB8 has been destroyed" << std::endl;
	}

	//
	// Public data members.
	//
public:
	//! Robot's name.
	_tstring name_;
};

}

void _tmain(int argc, TCHAR* argv[])
{
	try
	{
		using starwars::BB8;

		std::auto_ptr<BB8> bb8;
		bb8.reset(new BB8());
		if (bb8.get())
		{
			_tcout << _T("bb8 ptr is initialized") << std::endl;
			std::auto_ptr<BB8> bb81(bb8);
			if (bb81.get() && !bb8.get()) /* bb81 == bb8, bb8 == nullptr */
			{
				_tcout << _T("bb8 ptr is invalid") << std::endl;
				BB8* bb82 = bb81.release();
				if (bb82 && !bb81.get()) /* bb82 == bb8, bb81 == nullptr*/
				{
					_tcout << "Robot name: " << bb82->name_ << std::endl;
					delete bb82; /* destroy bb8 */
				}
			}
		}
	}
	catch (const std::exception& e)
	{
		_tcerr << _T("Error occurred: ") << e.what() << std::endl;
	}
}