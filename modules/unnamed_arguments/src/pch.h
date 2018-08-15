#pragma once

//////////////////////////////////////////////////////////////////////////
// STL includes and definitions.
//

#include <iostream>
#include <tchar.h>
#include <stdarg.h>

#ifdef _UNICODE
#define _tcout std::wcout
#else
#define _tcout std::cout
#endif
