#pragma once

#ifdef TESTDLL_EXPORTS
#define ZDLL_API __declspec(dllexport)
#include "targetver.h"
#else
#define ZDLL_API __declspec(dllimport)
#endif // TESTDLL_EXPORTS


#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>
#include "Time.h"
#include "Date.h"
#include "TimeDate.h"