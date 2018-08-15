#include "pch.h"
#include "Circle.h"
#include "Square.h"

void _tmain(int argc, TCHAR* argv[])
{
	try
	{
		std::stack<Shape*> box;

		Circle circle(Point(0, 0));
		Square* square = new Square(Point(0, 0));

		box.push(&circle);
		box.push(square);

		while (!box.empty())
		{
			Shape* s = box.top();
			s->Draw();
			s->Move(Point(1, 1));

			box.pop();
		}

		delete square;
	}
	catch (const std::exception& e)
	{
		_tcerr << "Error occurred: " << e.what() << std::endl;
	}
}