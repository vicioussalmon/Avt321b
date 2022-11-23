#include "pch.h"
#include "UchenLib.h"

#ifdef STAFFLIBRARY_EXPORTS

#define STAFFLIBRARY_API __declspec(dllexport)

#else

#define STAFFLIBRARY_API __declspec(dllimport)

#endif




extern "C++" STAFFLIBRARY_API 