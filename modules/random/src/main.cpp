#include "pch.h"

int main(int argc, char* argv[])
{
	try
	{
		{
			std::cout << "<<---------------------" << std::endl;
			// int, unsigned int, long, unsigned long, long long, unsigned long long.
			std::mt19937 gen(static_cast<unsigned int>(time(0)));
			std::uniform_int_distribution<unsigned int> uid(10, 20);
			std::cout << uid(gen) << std::endl;
			std::cout << "max: " << uid.param().a() << std::endl;
			std::cout << "min: " << uid.param().b() << std::endl;
			// bind
			auto roll = std::bind(uid, gen);
			std::cout << roll() << std::endl;
		}

		{
			std::cout << "<<---------------------" << std::endl;
			// float, double, long double
			std::mt19937 gen(static_cast<unsigned int>(time(0)));
			std::uniform_real_distribution<double> uid(0, 1);
			std::cout << uid(gen) << std::endl;
		}

		{
			std::cout << "<<---------------------" << std::endl;
			// sequence
			std::mt19937 gen(static_cast<unsigned int>(time(0)));
			std::uniform_int_distribution<unsigned int> uid(10, 200);
			const std::size_t N = 10;
			std::vector<unsigned int> v(N);
			std::generate(v.begin(), v.begin() + N, [&uid, &gen]() -> int
			{
				return uid(gen);
			});

			std::copy(v.begin(), v.end(), std::ostream_iterator<unsigned int>(std::cout, "\n"));
			auto mm = std::minmax_element(v.begin(), v.begin() + N);
			std::cout << "\nMin: " << *mm.first << "\nMax: " << *mm.second << std::endl;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error occurred: " << e.what() << std::endl;
	}

	return EXIT_SUCCESS;
}