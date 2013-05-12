// FunctionTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BasicFunctions.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	Identity< _a > a;
	Identity< _b > b;

	std::cout << "a(12.2) = " << a(12.2) << std::endl;

	auto f2 = a.operator+< Identity<_b> > (b);
	
	return 0;
}

