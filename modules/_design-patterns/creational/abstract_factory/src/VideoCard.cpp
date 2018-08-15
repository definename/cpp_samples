#include "pch.h"
#include "VideoCard.h"

VideoCard::VideoCard()
{ }

VideoCard::VideoCard(const _tstring& manufacturer)
	: manufacturer_(manufacturer)
{ }

VideoCard::~VideoCard()
{
	_tcout << _T("VideoCard has been destroyed") << std::endl;
}

_tstring VideoCard::GetManufacturer()
{
	return manufacturer_;
}

void VideoCard::Stop()
{
	_tcout << _T("VideoCard has been stopped") << std::endl;
}

void VideoCard::Start()
{
	_tcout << _T("VideoCard has been started") << std::endl;
}