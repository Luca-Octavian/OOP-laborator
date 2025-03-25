#include <iostream>
#include <cstring>
using namespace std;
#include "Number.h"

Number::Number(const char* value, int base)
{
	this->number = new char[65];
	for (int i = 0;i < strlen(value);i++)
	{
		this->number[i] = value[i];
	}
	this->number[strlen(value)] = '\0';
	this->base = base;
}

Number::~Number()
{
	delete[] this->number;
}

int Number::GetDigitsCount()
{
	return strlen(this->number);
}

int Number::GetBase()
{
	return this->base;
}

int Number::Char2Int()
{
	int i = 0;
	int rezultat = 0;
	int cifra;
	while (this->number[i] != '\0')
	{
		if (this->number[i] >= '0' && this->number[i] <= '9')
		{
			cifra=(this->number[i] - '0');
		}
		else if(this->number[i]>= 'A'&&this->number[i]<='Z')
		{
			cifra=(this->number[i] + 10 - 'A');
		}
		rezultat = rezultat * this->base + cifra;
		i++;
	}
	return rezultat;
}

void Number::SwitchBase(int newbase)
{
	int numar = Char2Int();
	char buffer[65];
	int rest;
	int i = 0;
	if (newbase < 2 || newbase>'Z')
	{
		cout << "baza invalida" << endl;
		return;
	}
	if (numar == 0)
	{
		delete[] this->number;
		this->number = new char[2];
		this->number[0] = 0;
		this->number[1] = '\0';
		this->base = newbase;
		return;
	}
	while (numar > 0)
	{
		rest = numar % newbase;
		if (rest < 10)
		{
			buffer[i] = rest + '0';
		}
		else
		{
			buffer[i] = rest + 'A' - 10;
		}
		i++;
		numar = numar / newbase;
	}
	this->base = newbase;
	delete[] this -> number;
	this->number = new char[i + 1];
	for(int index = 0;index < i;index++)
	{
		this->number[index] = buffer[i - index- 1];
	}
	this->number[i] = '\0';
}
void Number::Print()
{
	for (int i = 0;i < GetDigitsCount();i++)
	{
		cout << this->number[i];
	}
	cout << endl;
}
bool Number::operator>(Number& other)
{
	int base1 = this->Char2Int();
	int base2 = other.Char2Int();
	if (base1 > base2)
	{
		return true;
	}
	return false;
}
bool Number::operator<(Number& other)
{
	int base1 = this->Char2Int();
	int base2 = other.Char2Int();
	if (base1 < base2)
	{
		return true;
	}
	return false;
}
bool Number::operator==(Number& other)
{
	int base1 = this->Char2Int();
	int base2 = other.Char2Int();
	if (base1 == base2)
	{
		return true;
	}
	return false;
}
Number Number::operator+(Number& other)
{
	int newbase = max(this->base, other.base);
	int num1 = this->Char2Int();
	int num2 = other.Char2Int();
	int numar = num1 + num2;	
	char buffer[65];
	int rest;
	int i = 0;
	while (numar > 0)
	{
		rest = numar % newbase;
		if (rest < 10)
		{
			buffer[i] = rest + '0';
		}
		else
		{
			buffer[i] = rest + 'A' - 10;
		}
		i++;
		numar = numar / newbase;
	}
	buffer[i] = '\0';
	for (int index = 0;index < i;index++)
	{
		int aux = buffer[index];
		buffer[index] = buffer[i - index - 1];
		buffer[i - index - 1] = aux;
	}
	return Number(buffer, newbase);
}

Number Number::operator-(Number& other)
{
	int newbase = max(this->base, other.base);
	int num1 = this->Char2Int();
	int num2 = other.Char2Int();
	int numar = abs(num1 - num2);
	char buffer[65];
	int rest;
	int i = 0;
	while (numar > 0)
	{
		rest = numar % newbase;
		if (rest < 10)
		{
			buffer[i] = rest + '0';
		}
		else
		{
			buffer[i] = rest + 'A' - 10;
		}
		i++;
		numar = numar / newbase;
	}
	buffer[i] = '\0';
	for (int index = 0;index < i;index++)
	{
		int aux = buffer[index];
		buffer[index] = buffer[i - index - 1];
		buffer[i - index - 1] = aux;
	}
	return Number(buffer, newbase);
}

Number::Number(const Number& other) 
{
	this->base = other.base;
	int len = strlen(other.number);
	this->number = new char[len + 1];  
	strcpy_s(this->number, len+1, other.number);
}
Number::Number(Number&& other) 
{
	this->base = other.base;
	this->number = other.number;  
	other.number = nullptr;       
}

Number& Number::operator=(Number&& other)
{
	if (this != &other)
	{
		delete[] this->number;  
		this->base = other.base;
		this->number = other.number;  
		other.number = nullptr;       
	 }
	return *this;
}

Number& Number::operator=(Number& other)
{
	if (this != &other)
	{
		delete[] this->number;

		this->base = other.base;
		int len = strlen(other.number);
		this->number = new char[len + 1];  
		strcpy_s(this->number, len + 1, other.number);
	}
	return *this;
}
Number Number::operator--()
{
	int lungime = strlen(this->number);
	if (lungime == 1)
	{
		delete[] this->number;
		this->number = new char[2];
		this->number[0] = '0';
		this->number[1] = '\0';
	}
	else
	{
		for (int i = 0;i < lungime-1;i++)
		{
			this->number[i] = this->number[i + 1];
		}
		this->number[lungime - 1] = '\0';
	}
	return *this;
}