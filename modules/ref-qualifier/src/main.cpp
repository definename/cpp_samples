#include "pch.h"

template <typename T>
void PRINT_COLLECTION(T coll) {
	for (const auto& val : coll) {
		std::cout << val << " ";
	}
	std::cout << std::endl;
}

class Widget
{
public:
	Widget()
		: coll_{1, 2, 3, 4, 5} {
	}

public:
	using Coll = std::vector<int>;

public:
	Coll& Data() & {
		std::cout << "lvalue" << std::endl;
		return coll_;
	}

	Coll&& Data() && {
		std::cout << "rvalue" << std::endl;
		return std::move(coll_);
	}

public:
	std::vector<int> coll_;
};

Widget Creator() {
	return Widget();
}

int main(int argc, char* argv[])
{
	try {

		Widget w;
		decltype(auto) ref = w.Data();
		
		auto move = Creator().Data();
	}
	catch (const std::exception& e) {
		std::cerr << "Error occurred: " << e.what() << std::endl;
	}

	return EXIT_SUCCESS;
}