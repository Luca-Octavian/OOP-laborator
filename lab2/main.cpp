#include <iostream>
#include "Global.h"
#include "Student.h"
int main()
{
	Student a, b;
	char x[50], y[50];
	strcpy_s(x, 49, "Marian Boss");
	strcpy_s(y, 49, "Marian Boss");
	a.SetName(x);
	b.SetName(x);
	a.SetEng(10);
	b.SetEng(5.6);
	a.SetMath(7.4);
	b.SetMath(8.3);
	a.SetIst(3.1);
	b.SetIst(3.1);
	strcpy_s(x, 49, a.GetName());
	strcpy_s(y, 49, b.GetName());
	float mate1, mate2, eng1, eng2, ist1, ist2, avg1, avg2;
	mate1 = a.GetMath();
	mate2 = b.GetMath();
	eng1 = a.GetEng();
	eng2 = b.GetEng();
	ist1 = a.GetIst();
	ist2 = b.GetIst();
	avg1 = a.GetAvg();
	avg2 = b.GetAvg();
	std::cout << compname(a, b) << std::endl;
	std::cout << compist(a, b) << std::endl;
	std::cout << compeng(a, b) << std::endl;
	std::cout << compmath(a, b) << std::endl;
	std::cout << compavg(a, b) << std::endl;

}