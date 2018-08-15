#pragma once

namespace emulator
{

enum class VenueT : unsigned int
{
    UNKNOWN = 0,
    DEFINED
};

struct Venue
{
private:
    static std::vector<std::string> name_;
public:
    static std::string ToString(const unsigned int id)
    {
        return name_.at(id);
    }
};

} // namespace emulator