#pragma once

//////////////////////////////////////////////////////////////////////////
// STL includes and definitions.
//

#include <iostream>
#include <tchar.h>
#include <string>
#include <map>

#ifdef _UNICODE
#define _tcout std::wcout
#define _tcin std::wcin
#define _tstring std::wstring
#define _tcerr std::wcerr
#else
#define _tcin std::cin
#define _tcout std::cout
#define _tstring std::string
#define _tcerr std::cerr
#endif
