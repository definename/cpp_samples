#include "pch.h"

void print(const std::vector<std::string>& v);

int main()
{
	std::vector<std::string> vec;
	vec.push_back("");
	vec.push_back("stringone");
	vec.push_back("stringtwo");
	vec.push_back("");
	vec.push_back("stringthree");
	print(vec);

	std::vector<std::string>::iterator it = remove_if(
		vec.begin(), vec.end(), std::mem_fun_ref(&std::string::empty));
	print(vec);

	vec.erase(it, vec.end());
	print(vec);

	return 0;
}

void print(const std::vector<std::string>& v)
{
	std::for_each(v.begin(), v.end(), [](const std::string& str){ std::cout << str << std::endl;});
}