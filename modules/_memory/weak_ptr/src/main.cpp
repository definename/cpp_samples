#include "pch.h"

class Widget
{
	//
	// Construction and destruction.
	//
public:
	//! Constructor.
	Widget() = default;
	//! Destructor.
	~Widget() = default;

	//
	// Public interface.
	//
public:
	//! Returns name.
	std::string GetName() const
	{
		return name_;
	}

	// Private data members.
private:
	//! Widget name.
	std::string name_;
};

void _tmain(int argc, TCHAR* argv[])
{
	try
	{
		std::shared_ptr<Widget> spw = std::make_shared<Widget>();
		std::cout << "shared counter " << spw.use_count() << std::endl;

		std::weak_ptr<Widget> wpw(spw);
	
		std::cout << "shared counter " << spw.use_count() << std::endl;
		std::cout << "weak " << (wpw.expired() ? "is" : "is not") << " expired" << std::endl;

		spw = nullptr;
// 		spw.reset();
// 		wpw.reset();

		std::cout << "shared counter " << spw.use_count() << std::endl;
		std::cout << "weak " << (wpw.expired() ? "is" : "is not") << " expired" << std::endl;

		std::shared_ptr<Widget> null = wpw.lock();
		if (!null)
			std::cout << "Null pointer" << std::endl;

		std::shared_ptr<Widget> exception(wpw);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error occurred: " << e.what() << std::endl;
	}
}