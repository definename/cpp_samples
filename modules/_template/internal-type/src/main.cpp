#include "pch.h"
#include "Obj.h"

int main(int argc, char* argv[])
{
	using ObjInt = Obj<int>;
	ObjInt obj;
	if (obj.GetStatus() == ObjInt::Status::On)
	{
		std::cout << "Bingo..." << std::endl;
	}

	return EXIT_SUCCESS;
}