#include <iostream>
using namespace std;
#include "Number.h"

int main()
{
	Number x= Number("123123AA", 11);
	Number y = Number("ADB371", 16);
	Number z = x + y;
	Number w = x - y;
	if (x > y)
	{
		cout << "x e mai mare" << endl;
		
	}
	else
	{
		cout << "y e mai mare" << endl;
	}
	z.Print();
	w.Print();
	w = x;
	Number num1 = Number("123", 4);
	--num1;
	num1.Print();
	return 0;
	
}