#pragma once

//////////////////////////////////////////////////////////////////////////
// STL includes and definitions.
//

#include <iostream>
#include <tchar.h>
#include <fstream>
#include <sstream>
#include <algorithm>

#ifdef _UNICODE
#define _tcout std::wcout
#define _tcin std::wcin
#define _tstring std::wstring
#define _tcerr std::wcerr
#define _tostream std::wostream
#define _tistream std::wistream
#define _tofstream std::wofstream
#define _tifstream std::wifstream
#define _tstringstream std::wstringstream
#else
#define _tcin std::cin
#define _tcout std::cout
#define _tstring std::string
#define _tcerr std::cerr
#define _tostream std::ostream
#define _tistream std::istream
#define _tofstream std::ofstream
#define _tifstream std::ifstream
#define _tstringstream std::stringstream
#endif

//////////////////////////////////////////////////////////////////////////
// Boost includes and definitions.
//

#include "boost/filesystem.hpp"
#include "boost/uuid/uuid.hpp"
#include "boost/uuid/random_generator.hpp"
#include "boost/uuid/uuid_io.hpp"
