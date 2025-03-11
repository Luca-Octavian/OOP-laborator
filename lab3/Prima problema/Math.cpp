#include <iostream>
#include <cstdarg> 
#include <cstring>
using namespace std;
#include "Math.h"
int Math::Add(int x, int y)
{
	return x + y;
}
int Math::Add(int x, int y, int z)
{
	return x + y + z;
}
int Math::Add(double x, double y)
{
	return x + y;
}
int Math::Add(double x, double y, double z)
{
	return x + y + z;
}
int Math::Mul(int x, int y)
{
	return x * y;
}
int Math::Mul(int x, int y, int z)
{
	return x * y * z;
}
int Math::Mul(double x, double y)
{
	return x * y;
}
int Math::Mul(double x, double y, double z)
{
	return x * y * z;
}
int Math::Add(int count, ...)
{
	if (count < 1)
	{
		return 0;
	}
	va_list parametru_actual;
	va_start(parametru_actual, count);
	int suma = 0;
	for (int i = 0;i < count;i++)
	{
		suma += va_arg(parametru_actual, int);
	}
	return suma;
}
char* Math::Add(const char* s1, const char* s2)
{
	if (!s1 || !s2) 
	{
		return nullptr;
	}
	int x = strlen(s1);
	int y = strlen(s2);
	int count = x + y;
	char *s = new char[count + 1];
	strcpy_s(s, count+1, s1);
	strcat_s(s, count+1, s2);
	return s;
}
