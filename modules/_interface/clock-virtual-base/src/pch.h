#pragma once

//////////////////////////////////////////////////////////////////////////
// STL includes and definitions.
//

#include <iostream>
#include <tchar.h>
#include <typeinfo>
#include <deque>

#ifdef _UNICODE
#define _tcout std::wcout
#define _tcin std::wcin
#define _tstring std::wstring
#define _tcerr std::wcerr
#define _tostream std::wostream
#define _tistream std::wistream
#else
#define _tcin std::cin
#define _tcout std::cout
#define _tstring std::string
#define _tcerr std::cerr
#define _tostream std::ostream
#define _tistream std::istream
#endif
