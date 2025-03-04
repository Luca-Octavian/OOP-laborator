#include <iostream>
using namespace std;
#include "Student.h"
void Student::SetName(char name[50])
{
	strcpy_s(this->name, 49, name);
}
void Student::SetMath(float x)
{
	this->math = x;
}
void Student::SetIst(float x)
{
	this->ist = x;
}
void Student::SetEng(float x)
{
	this->eng = x;
}
char* Student::GetName()
{
	return this->name;
}
float Student::GetMath()
{
	return this->math;
}
float Student::GetIst()
{
	return this->ist;
}
float Student::GetEng()
{
	return this->eng;
}
float Student::GetAvg()
{
	float mediamate = this->math;
	float mediaeng = this->eng;
	float mediaist = this->ist;
	return (mediamate + mediaeng + mediaist) / 3;
}