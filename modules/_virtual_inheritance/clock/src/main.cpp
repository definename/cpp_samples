#include "pch.h"
#include "Clock.h"

typedef Window* WindowPtr;

void _tmain(int argc, TCHAR* argv[])
{
	try
	{
		std::deque<WindowPtr> box;

		WindowBorder* winBorder = new WindowBorder;
		box.push_front(winBorder);

		WindowMenu winMenu;
		box.push_back(&winMenu);

		Clock* clock = new Clock;
		box.insert(box.begin(), clock);

		for (WindowPtr i : box)
		{
			_tcout << typeid(*i).name() << std::endl;
			i->Draw();
			_tcout << std::endl;
		}
		box.clear();

		delete clock;
		delete winBorder;
	}
	catch (const std::exception& e)
	{
		_tcerr << _T("Error occurred: ") << e.what() << std::endl;
	}
}