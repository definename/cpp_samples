#include "pch.h"

template <typename InputIterator, typename Predicate>
std::vector<typename std::iterator_traits<InputIterator>::value_type> find_all(InputIterator first, InputIterator last, Predicate pred)
{
	typename std::vector<std::iterator_traits<InputIterator>::value_type> res;
	while (true)
	{
		first = std::find_if(first, last, pred);
		if (first == last)
			break;

		res.push_back(*first);
		++first;
	}
	return res;
}

bool predicat(const int& num);
void FindIfPredicat(const std::vector<int>& v);
void FindIfBinderFunctor(const std::vector<int>& v);
void FindIfInverterBinderFunctor(const std::vector<int>& v);
void FindIfEmptyStringMemFunRef(const std::vector<std::string>& v);
void FindIfEmptyStringMemFun(const std::vector<std::string*>& v);
void FindIfIsAllNumber(const std::string& str);
void FindIfFunctionalObject(const std::string& str);
void FindAllTest();

int main()
{
	std::vector<int> vec;
	for (int i = -10; i != 10; ++i)
	{
		vec.push_back(i);
	}

	FindIfPredicat(vec);
	FindIfBinderFunctor(vec);
	FindIfInverterBinderFunctor(vec);

	std::vector<std::string> vecStr;
	vecStr.push_back("isnotemptystring");
	vecStr.push_back("");
	FindIfEmptyStringMemFunRef(vecStr);

	std::vector<std::string*> vecStrPtr;
	vecStrPtr.push_back(new std::string("isnotemptystring"));
	vecStrPtr.push_back(new std::string(""));
	FindIfEmptyStringMemFun(vecStrPtr);

	std::string str("123123123123K234");
	FindIfIsAllNumber(str);
	FindIfFunctionalObject(str);

	FindAllTest();

	return 0;
}

bool predicat(const int& num)
{
	return (num == 5);
}

void FindIfPredicat(const std::vector<int>& v)
{
	std::vector<int>::const_iterator it;
	it = std::find_if(v.begin(), v.end(), predicat);
	if (it != v.end())
		std::cout << "Detected: " << *it << std::endl;
}

void FindIfBinderFunctor(const std::vector<int>& v)
{
	std::vector<int>::const_iterator it;
	it = std::find_if(v.begin(), v.end(), std::bind2nd(std::greater<int>(), 5));
	if (it != v.end())
		std::cout << "Detected: " << *it << std::endl;
}

void FindIfInverterBinderFunctor(const std::vector<int>& v)
{
	std::vector<int>::const_iterator it;
	it = std::find_if(v.begin(), v.end(), std::not1(std::bind2nd(std::greater<int>(), 5)));
	if (it != v.end())
		std::cout << "Detected: " << *it << std::endl;
}

void FindIfEmptyStringMemFunRef(const std::vector<std::string>& v)
{
	std::vector<std::string>::const_iterator it;
	it = std::find_if(v.begin(), v.end(), std::mem_fun_ref(&std::string::empty));
	if (it != v.end())
		std::cout << "Detected: " << it - v.begin() << std::endl;
}
void FindIfEmptyStringMemFun(const std::vector<std::string*>& v)
{
	std::vector<std::string*>::const_iterator it;
	it = std::find_if(v.begin(), v.end(), std::mem_fun(&std::string::empty));
	if (it != v.end())
		std::cout << "Detected: " << it - v.begin() << std::endl;
}

void FindIfIsAllNumber(const std::string& str)
{
	std::string::const_iterator it;
	it = std::find_if(str.begin(), str.end(), std::not1(std::ptr_fun(::isdigit)));
	if (it != str.end())
		std::cout << "Detected: " << *it << std::endl;
}

class myIsDigit : public std::unary_function<char, bool>
{
public:
	bool operator() (char c) const { return (::isdigit(c) != 0); }
	// Also can use instead
	//bool operator() (char c) const { return (!!::isdigit(c)); }
};

void FindIfFunctionalObject(const std::string& str)
{
	std::string::const_iterator it;
	it = std::find_if(str.begin(), str.end(), std::not1(myIsDigit()));
	if (it != str.end())
		std::cout << "Detected: " << *it << std::endl;
}

void FindAllTest()
{
	std::cout << "Find all test: ";
	std::vector<int> vec(10, 9);
	int find = 10;
	vec.at(0) = find;
	vec.at(5) = find;

	std::vector<int> all = find_all(vec.begin(), vec.end(), std::bind2nd(std::equal_to<int>(), find));
	std::for_each(all.begin(), all.end(), [](int i) { std::cout << i << " "; });
	std::cout << std::endl;
}