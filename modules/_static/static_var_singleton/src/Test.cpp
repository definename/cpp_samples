#include "pch.h"
#include "Test.h"

namespace emulator
{

bool Test::isNG_ = false;

Test::Test()
{

}

bool Test::IsNG() const
{
	return isNG_;
}

void Test::SetNG(const bool ng)
{
	isNG_ = ng;
}

} // namespace emulator
