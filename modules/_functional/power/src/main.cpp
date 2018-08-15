#include "pch.h"

struct Darth
{
	//
	// Construction and destruction.
	//
public:
	//! Constructor.
	Darth(const _tstring& name)
		: name_(name)
	{ }

	//
	// Public interface.
	//
public:
	//! Function call operator.
	void operator()(const int power) const
	{
		_tcout << name_ << " power: " << power << std::endl;
	}

	//
	// Private data members.
	//
private:
	//! Name.
	const _tstring name_;
};

struct Luke
{
	//
	// Construction and destruction.
	//
public:
	//! Constructor.
	Luke(const _tstring& name)
		: name_(name)
	{ }

	//
	// Public interface.
	//
public:
	//! Function call operator.
	void operator()(const int power) const
	{
		_tcout << name_ << " power: " << power << std::endl;
	}

	//
	// Private data members.
	//
private:
	//! Name.
	const _tstring name_;
};

//! Power template.
template <typename TCharacter>
void Power(TCharacter ch, int power);

void _tmain(int argc, TCHAR* argv[])
{
	Power(Darth(_T("Darth")), 80);
	Power(Luke(_T("Luke")), 90);
}

template <typename TCharacter>
void Power(TCharacter ch, int power)
{
	ch(power);
}