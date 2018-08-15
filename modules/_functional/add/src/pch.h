#pragma once

//////////////////////////////////////////////////////////////////////////
// STL includes and definitions.
//

#include <iostream>
#include <tchar.h>
#include <numeric>
#include <forward_list>

#ifdef _UNICODE
#define _tcout std::wcout
#define _tstring std::wstring
#else
#define _tcout std::cout
#define _tstring std::string
#endif
