#include "pch.h"

int main(int argc, char* argv[])
{
	try
	{
		{
			std::string data("123.321.456.654");
			std::regex reg(R"((\d+)\.(\d+)\.(\d+)\.(\d+))");
			//std::regex reg(R"(([0-9]+)\.([0-9]+)\.([0-9]+)\.([0-9]+))");
			std::smatch m;
			if (std::regex_match(data, m, reg))
			{
				std::cout << m.size() << std::endl;
				//std::cout << m[0].str() << std::endl;
				std::cout << m[1].str() << std::endl;
				std::cout << m[2].str() << std::endl;
				std::cout << m[3].str() << std::endl;
				std::cout << m[4].str() << std::endl;
			}
		}

		{
			std::string data("antivirus.name");
			std::regex reg(R"(([a-z0-9]+)\.([a-z0-9]+))");
			std::smatch m;
			if (std::regex_match(data, m, reg))
			{
				std::cout << m.size() << std::endl;
				std::cout << m[0].str() << std::endl;
				std::cout << m[1].str() << std::endl;
				std::cout << m[2].str() << std::endl;
			}
		}

        {
            std::string line("2018-03-07 12:24:52.641 INFO  /?advId=23&offerId=14&campaignId=51x3.1520406653.5a9f907d4c2eb&ip=27.4.53.12&timestamp=2018-03-07+07:13:54&key=WaxUjIYMxH3sTBNRjEMGcmWOWPMuyzAF");
            //std::string line("2018-03-0712:24:52.641INFO/?advId=23&offerId=14&campaignId=51x3.1520406653.5a9f907d4c2eb&ip=27.4.53.12&timestamp=2018-03-07+07:13:54&key=WaxUjIYMxH3sTBNRjEMGcmWOWPMuyzAF");
            //std::regex linereg(R"(([0-9-:\.]+)(INFO)(.*))");
            std::regex linereg(R"((\d{4})-(\d{2})-(\d{2})\s(\d{2}):(\d{2}):(\d{2})\.(\d{3})(\s{1}INFO\s{2})(.*))");
            std::smatch m;
            if (std::regex_match(line, m, linereg))
            {
                std::cout << m.size() << std::endl;
                std::cout << m[0].str() << std::endl;

                std::cout << m[1].str() << std::endl;
                std::cout << m[2].str() << std::endl;
                std::cout << m[3].str() << std::endl;
                std::cout << m[4].str() << std::endl;
                std::cout << m[5].str() << std::endl;
                std::cout << m[6].str() << std::endl;
                std::cout << m[7].str() << std::endl;
                std::cout << m[8].str() << std::endl;
                std::cout << m[9].str() << std::endl;

                std::vector<std::string> params;
                std::istringstream f(m[9].str());
                std::string s;
                while (std::getline(f, s, '&'))
                {
                    std::cout << s << std::endl;
                    params.push_back(s);
                }
            }
        }
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error occurred: " << e.what() << std::endl;
	}

	return EXIT_SUCCESS;
}