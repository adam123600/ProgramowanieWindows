// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "testDll.h"

int main()
{
	
	Date d(2020, 5, 15);
	std::cout << "d = " << d << std::endl;
	
	Time t(20, 35, 0);
	std::cout << "d = " << t << std::endl;

	TimeDate td1(t, d);
	TimeDate td2(td1);

	std::cout << std::endl << "td2 = " << td2 << std::endl;

    return 0;
}

