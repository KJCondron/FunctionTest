// FunctionTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BasicFunctions.h"
#include <iostream>

#include <boost/mpl/for_each.hpp>

#ifdef FOR_PRINTING
	struct printer
	{
		template < typename T > void operator()( T )
		{
			std::cout << T::toString() << std::endl;
		}
	};
#endif

int _tmain(int argc, _TCHAR* argv[])
{
	Identity< _a > a;
	Identity< _b > b;

	std::cout << "a(12.2) = " << a(12.2) << std::endl;

	auto f2 = a + b;

	Param< _a, _b > pab(1.4, 2.5);
	Param< _a > pa(1.2);
	Param< _a > pa2(pab);

	std::cout << f2.toString() << f2(pab) << std::endl;

	typedef ParamCombiner< Param<_a>, Param<_b> >::types types;

#ifdef FOR_PRINTING
	mpl::for_each< types >( printer() );
#endif
	
	return 0;
}

