#include "pch.h"

// Prints bits.
template<typename TData>
void Bits(TData value);
// Header as hex value.
std::size_t Header(const std::size_t& in);

//! Packs uint64_t into 8 byte array.
std::array<unsigned char, sizeof(uint64_t)> Pack(const uint64_t& data);
//! Unpacks 8 byte array into uint64_t.
uint64_t Unpack(const std::array<unsigned char, sizeof(uint64_t)>& bytes);

int _tmain(int argc, TCHAR* argv[])
{
	using  TType = size_t;
	const TType in = /*4919131752989213764*/std::numeric_limits<size_t>::max()/*2143281199*/;

	Bits<TType>(in);
	std::cout << in << std::endl;
	std::array<unsigned char, sizeof(uint64_t)> bytes = Pack(static_cast<uint64_t>(in));
	for (const auto& val : bytes)
	{
		Bits<unsigned char>(val);
	}
	TType out = static_cast<TType>(Unpack(bytes));
	std::cout << out << std::endl;
	Bits<TType>(out);

	return EXIT_SUCCESS;
}

std::array<unsigned char, sizeof(uint64_t)> Pack(const uint64_t& data)
{
	std::array<unsigned char, sizeof(uint64_t)> bytes;

	std::size_t bits = sizeof(uint64_t) * 8;
	for (std::size_t offset = 0; offset < bits; offset += 8)
	{
		bytes[offset / 8] = (data >> offset) & 0xFF;
	}
	std::reverse(bytes.begin(), bytes.end());

	return bytes;
}

uint64_t Unpack(const std::array<unsigned char, sizeof(uint64_t)>& bytes)
{
	uint64_t header = 0;

	for (int i = 0, offset = (sizeof(uint64_t) - 1) * 8; offset >= 0; ++i, offset -= 8)
	{
		uint64_t byte = static_cast<uint64_t>(bytes.at(i));
		header |= (byte << offset);
	}

	return header;
}

template<typename TData>
void Bits(TData value)
{
	const TData SHIFT = 8 * sizeof(TData) - 1;
	const TData MASK = TData(1) << SHIFT;

	for (TData i = 1; i <= SHIFT + 1; ++i)
	{
		_tcout << (value & MASK ? '1' : '0');
		value = value << 1;
		if (i % 8 == 0)
			_tcout << ' ';
	}
	_tcout << std::endl;
}

std::size_t Header(const std::size_t& in)
{
	std::ostringstream oheader;
	oheader << std::setw(8) << std::hex << in;

	std::string headerStr(oheader.str());

	std::istringstream iheader(headerStr);
	std::size_t out;
	iheader >> std::hex >> out;

	return out;
}