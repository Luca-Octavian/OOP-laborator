#include <iostream>
#include "Canvas.h"
using namespace std;
int main()
{
	Canvas c(100, 100);
	c.DrawCircle(40, 40, 10, '*');
	c.FillCircle(40, 40, 10, '*');
	c.Clear();
	c.DrawRect(30, 60, 70, 80, '*');
	c.FillRect(30, 60, 70, 80, 'A');
	c.Clear();
	c.DrawLine(60, 80, 30, 90, '*');
	c.Clear();
	c.SetPoint(70, 70, '*');
	c.Print();
}