#include "pch.h"
#include "HashUtils.h"

struct Customer
{
	friend std::ostream& operator << (std::ostream& ostr, const Customer& c)
	{
		return ostr << "[" << c.fname_ << ", " << c.lname_ << ", " << c.number_ << "]";
	}

	const std::string fname_;
	const std::string lname_;
	const int number_;
};

int main()
{
	auto hash = [](const Customer& c) {
		return std::hash<std::string>()(c.fname_) + std::hash<std::string>()(c.lname_);
	};

	auto eq = [](const Customer& c1, const Customer& c2) {
		return c1.number_ == c2.number_;
	};

	std::unordered_set<Customer, decltype(hash), decltype(eq)> coll(10, hash, eq);
	coll.insert({ "Bill", "Gates", 1 });
	coll.insert({ "Steve", "Jobs", 2 });
	coll.insert({ "Huyo", "Moyo", 3 });

	PrintHashState(coll);

	return 0;
}