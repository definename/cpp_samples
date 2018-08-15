#include "pch.h"
#include "Header.h"

int main(int argc, char* argv[])
{
    std::cout << emulator::Venue::ToString(static_cast<unsigned int>(emulator::VenueT::UNKNOWN)) << std::endl;

    return 0;
}