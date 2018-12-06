#include "pch.h"
#include "Roads.h"

Roads::Roads()
{
	graph_ = {
		{ 0, 5, 0, 10, 6},
		{ 5, 0, 5, 8, 0 },
		{ 0, 5, 0, 4, 0 },
		{ 10, 8, 4, 0, 7},
		{ 6, 0, 0, 7, 0 }
	};
}