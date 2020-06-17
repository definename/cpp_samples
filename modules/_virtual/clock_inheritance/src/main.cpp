#include <iostream>
#include <typeinfo>
#include <queue>

#include "Clock.h"

typedef Window* WindowPtr;

int main(int argc, char* argv[])
{
	try {
		std::deque<WindowPtr> box;

		WindowBorder* winBorder = new WindowBorder;
		box.push_front(winBorder);

		WindowMenu winMenu;
		box.push_back(&winMenu);

		Clock* clock = new Clock;
		box.insert(box.begin(), clock);

		for (WindowPtr i: box) {
			std::cout << typeid(*i).name() << std::endl;
			i->Draw();
			std::cout << std::endl;
		}
		box.clear();

		delete clock;
		delete winBorder;
	}
	catch (const std::exception& e) {
		std::cerr << "Error occurred: " << e.what() << std::endl;
	}
	return EXIT_SUCCESS;
}