#include "pch.h"
#include "AMDFactory.h"
#include "IntelFactory.h"

void Create(IFactory* factory);

void _tmain(int argc, TCHAR* argv[])
{
	try
	{
		AMDFactory amd;
		Create(&amd);

		IntelFactory* intel = new IntelFactory();
		Create(intel);

		delete intel;
	}
	catch (const std::exception& e)
	{
		_tcerr << "Error corrupted: " << e.what() << std::endl;
	}
}

void Create(IFactory* factory)
{
	IDevice* processor = factory->GetProcessorInstance();
	_tstring pStr = processor->GetManufacturer();
	_tcout << pStr << std::endl;
	processor->Start();
	processor->Stop();

	delete processor;

	IDevice* video = factory->GetVideoCardInstance();
	_tstring vStr = video->GetManufacturer();
	_tcout << vStr << std::endl;
	video->Start();
	video->Stop();

	delete video;
}