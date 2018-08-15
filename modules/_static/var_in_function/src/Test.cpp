#include "pch.h"
#include "Test.h"

namespace emulator
{

int Test::Do()
{
    static int value = 100;
    return value++;
}

} // namespace emulator
