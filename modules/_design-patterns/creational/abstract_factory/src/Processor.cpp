#include "pch.h"
#include "Processor.h"

Processor::Processor()
{ }

Processor::Processor(const _tstring& manufacturer)
	: manufacturer_(manufacturer)
{ }

Processor::~Processor()
{
	_tcout << _T("Processor has been destroyed") << std::endl;
}

_tstring Processor::GetManufacturer()
{
	return manufacturer_;
}

void Processor::Start()
{
	_tcout << _T("Processor has been started") << std::endl;
}

void Processor::Stop()
{
	_tcout << _T("Processor has been stopped") << std::endl;
}