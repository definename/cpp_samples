#pragma once

template <typename T>
void PrintHashState(const T& coll)
{
	for (int i = 0; i != coll.bucket_count(); ++i)
	{
		std::cout << "b[" << std::setw(2) << i << "]: ";
		for (auto pos = coll.begin(i); pos != coll.end(i); ++pos)
		{
			std::cout << *pos << " ";
		}
		std::cout << std::endl;
	}
}