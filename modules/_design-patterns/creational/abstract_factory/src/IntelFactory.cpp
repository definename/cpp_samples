#include "pch.h"
#include "IntelFactory.h"
#include "Processor.h"
#include "VideoCard.h"

IntelFactory::IntelFactory()
{ }

IntelFactory::~IntelFactory()
{
	_tcout << "Intel factory has been destroyed" << std::endl;
}

IDevice* IntelFactory::GetProcessorInstance()
{
	return new Processor(_T("Intel"));
}

IDevice* IntelFactory::GetVideoCardInstance()
{
	return new VideoCard(_T("Intel"));
}