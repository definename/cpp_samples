#include "pch.h"
#include "AMDFactory.h"
#include "Processor.h"
#include "VideoCard.h"

AMDFactory::AMDFactory()
{ }

AMDFactory::~AMDFactory()
{
	_tcout << "AMD factory has been destroyed" << std::endl;
}

IDevice* AMDFactory::GetProcessorInstance()
{
	return new Processor(_T("AMD"));
}

IDevice* AMDFactory::GetVideoCardInstance()
{
	return new VideoCard(_T("AMD"));
}