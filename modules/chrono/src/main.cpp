#include "pch.h"
#include "Utils.h"

int main(int argc, char* argv[])
{
	try
	{
		{
			std::cout << "<<---------------------" << std::endl;
			std::this_thread::sleep_for(std::chrono::duration<int, std::milli>(1000));
			std::cout << "One second sleep" << std::endl;
			//std::this_thread::sleep_for(std::chrono::seconds(1));
			//std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(1));
		}

		{
			std::cout << "<<---------------------" << std::endl;
			std::cout << "Time now: " << utils::TimePointAsString(std::chrono::system_clock::now()) << std::endl;
			std::cout << "Epoch: " << utils::TimePointAsString(std::chrono::system_clock::time_point()) << std::endl;

			std::chrono::system_clock::time_point tp = utils::MakeTimePoint(2010, 1, 1, 0, 0);
			std::cout << "Conversion: " << utils::TimePointAsString(tp) << std::endl;
		}

		{
			std::cout << "<<---------------------" << std::endl;
			std::chrono::milliseconds ms(7255042);
			std::chrono::hours hh = std::chrono::duration_cast<std::chrono::hours>(ms);
			std::chrono::minutes mm = std::chrono::duration_cast<std::chrono::minutes>(ms % std::chrono::hours(1));
			std::chrono::seconds ss = std::chrono::duration_cast<std::chrono::seconds>(ms % std::chrono::minutes(1));;
			std::chrono::milliseconds msec = std::chrono::duration_cast<std::chrono::milliseconds>(ms % std::chrono::seconds(1));

			std::cout << "raw: " << hh << "::" << mm << "::" << ss << "::" << msec << std::endl;
			std::cout << std::setfill('0')
				<< std::setw(2) << hh.count() << "::"
				<< std::setw(2) << mm.count() << "::"
				<< std::setw(2) << ss.count() << "::"
				<< std::setw(3) << msec.count() << std::endl;
		}

        {
            std::cout << utils::MakeTimeStamp<std::chrono::milliseconds>() << std::endl;
            std::cout << utils::MakeTimeStamp<std::chrono::seconds>(2018, 03, 07, 12, 24, 52) << std::endl;

			std::tm tm = {};
			//std::stringstream ss("Jan 9 2014 12:35:34");
			std::stringstream ss("2018-03-07 12:24:52");
			ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
			auto tp = std::chrono::system_clock::from_time_t(std::mktime(&tm));
			std::cout << std::chrono::duration_cast<std::chrono::seconds>(tp.time_since_epoch()).count() << std::endl;
        }
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error occurred: " << e.what() << std::endl;
	}

	return EXIT_SUCCESS;
}