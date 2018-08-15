#include "pch.h"

template <typename T>
void PRINT_COLLECTION(T cont)
{
	for (const auto& val : cont)
	{
		std::cout << val << " ";
	}
	std::cout << std::endl;
}

void Func(int& val)
{
	std::cout << val << std::endl;
	val++;
}

struct Obj
{
	void SetName(const std::string& name) {
		name_ = name;
	}
	std::string GetName(const std::string &name) const {
		return name;
	}
	std::string GetName() const {
		return name_;
	}

	std::string name_;
};

int main(int argc, char* argv[])
{
	try
	{
		{
			// Global function.
			int v = 10;
			auto f = std::bind(Func, std::ref(v));
			f();
			std::cout << v << std::endl;
		}

		{
			// Member function.
			Obj obj;
			std::bind(&Obj::SetName, std::placeholders::_1, "Name")(obj);
			std::cout << obj.name_ << std::endl;

			// Overloaded member function.
			{
				auto callback = std::bind(static_cast<std::string(Obj::*)(const std::string &) const>(&Obj::GetName), obj, std::placeholders::_1);
				std::cout << callback("CustomName") << std::endl;
			}

			{
				auto callback = std::bind(static_cast<std::string(Obj::*)() const>(&Obj::GetName), obj);
				std::cout << callback() << std::endl;
			}
		}

		std::deque<int> c;
		for (int i = 1; i != 11; ++i) {
			c.emplace_back(i * 10);
		}
		PRINT_COLLECTION(c);

		auto pred = std::bind(
			std::logical_and<bool>(),
			std::bind(std::greater_equal<int>(), std::placeholders::_1, 50),
			std::bind(std::less_equal<int>(), std::placeholders::_1, 90));
		c.erase(std::remove_if(c.begin(), c.end(), pred), c.end());

		PRINT_COLLECTION(c);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error occurred: " << e.what() << std::endl;
	}

	return EXIT_SUCCESS;
}