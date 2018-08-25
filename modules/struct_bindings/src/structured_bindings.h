#pragma once

namespace cpp17
{

//! Bind struct type.
struct ToBind
{
	std::string name_;
	int number_;
};

//! Test structured bindings.
void TestStructuredBinding();

} // namespace cpp17