#pragma once
#include <UchenLib.h>
#include <SchoolLib.h>
#include <StudentLib.h>
#include <CollageLib.h>

#ifdef CUMTROL_EXPORTS

#define CUMTROL_API __declspec(dllexport)

#else

#define CUMTROL_API __declspec(dllimport)

#endif 
class Osn {
	void creating(Uchen** List, int size);
	void del(Uchen** List, int& size);
	void add(Uchen** List, int& size);
	void edit(Uchen** List, int& size);
	void individum(Uchen** List, int size);
	void printplace(Uchen** List, int size);
	void print(Uchen** List, int size);
public:
	void main();
	~Osn() {};
};
extern "C++" CUMTROL_API void cun();