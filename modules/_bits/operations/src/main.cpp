#include "pch.h"

using type = unsigned int;
// Prints bits.
template<typename TType>
void Bits(TType value);
// Determine byte order.
void ByteOrder();


int _tmain(int argc, TCHAR* argv[])
{
	ByteOrder();

	type number1 = std::numeric_limits<type>::max();;
	type number2 = 1;
	{
		Bits<type>(number1);
		Bits<type>(number2);
		Bits<type>(number1 & number2);
		_tcout << std::endl;
	}

	{
		Bits<type>(number1);
		Bits<type>(number2);
		Bits<type>(number1 | number2);
		_tcout << std::endl;
	}

	{
		Bits<type>(number1);
		Bits<type>(number2);
		Bits<type>(number1 ^ number2);
		_tcout << std::endl;
	}

	{
		Bits<type>(number1);
		Bits<type>(~number1);
		_tcout << std::endl;
	}

	return EXIT_SUCCESS;
}

template<typename TType>
void Bits(TType value)
{
	const TType SHIFT = 8 * sizeof(TType) - 1;
	const TType MASK = TType(1) << SHIFT;

	for (TType i = 1; i <= SHIFT + 1; ++i)
	{
		_tcout << (value & MASK ? '1' : '0');
		value = value << 1;
		if (i % 8 == 0)
			_tcout << ' ';
	}
	_tcout << std::endl;
}

void ByteOrder()
{
	unsigned short x = 1;
	Bits<unsigned short>(x);
	unsigned char y = *(reinterpret_cast<unsigned char*>(&x));
	Bits<unsigned char>(y);

	if (x == 0)
		_tcout << _T("big-endian");
	else if (x == 1)
		_tcout << _T("little-endian");
	_tcout << std::endl;
}