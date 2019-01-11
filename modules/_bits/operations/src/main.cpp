#include "pch.h"

using type = unsigned int;
// Prints bits.
template<typename TType>
void Bits(TType value);
// Determine byte order.
void ByteOrder();


int _tmain(int argc, TCHAR* argv[])
{
	logger::InitializeLog("console");

	ByteOrder();
	logger::log->info("");

	type number1 = std::numeric_limits<type>::max();
	type number2 = 1;
	{
		Bits<type>(number1);
		Bits<type>(number2);
		Bits<type>(number1 & number2);
		logger::log->info("");
	}

	{
		Bits<type>(number1);
		Bits<type>(number2);
		Bits<type>(number1 | number2);
		logger::log->info("");
	}

	{
		Bits<type>(number1);
		Bits<type>(number2);
		Bits<type>(number1 ^ number2);
		logger::log->info("");
	}

	{
		Bits<type>(number1);
		Bits<type>(~number1);
		logger::log->info("");
	}

	logger::UninitializeLog();

	return EXIT_SUCCESS;
}

template<typename TType>
void Bits(TType value)
{
	const TType SHIFT = 8 * sizeof(TType) - 1;
	const TType MASK = TType(1) << SHIFT;

	std::ostringstream res;
	for (TType i = 1; i <= SHIFT + 1; ++i)
	{
		res << (value & MASK ? '1' : '0');
		value = value << 1;
		if (i % 8 == 0)
			res << ' ';
	}
	logger::log->info(res.str());
}

void ByteOrder()
{
	unsigned short x = 1;
	Bits<unsigned short>(x);
	unsigned char y = *(reinterpret_cast<unsigned char*>(&x));
	Bits<unsigned char>(y);

	if (x == 0) {
		logger::log->info("big-endian");
	}
	else if (x == 1) {
		logger::log->info("little-endian");
	}
}