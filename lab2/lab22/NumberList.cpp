#include <iostream>
#include "NumberList.h";

void NumberList::Init()
{
	this->count = 0;
}
bool NumberList::Add(int x)
{
	
	if (this->count >= 10)
		return false;
	this->numbers[this->count] = x;
	this->count++;
	return true;
}
void NumberList::Sort()
{
	for (int i = 0;i < this->count;i++)
	{
		for (int j = i + 1;j < this->count;j++)
		{
			if (this->numbers[i] > this->numbers[j])
			{
				 int aux = this->numbers[i];
				 this->numbers[i] = this->numbers[j];
				 this->numbers[j] = aux;
			}
		}
	}
}
void NumberList::Print()
{
	for (int i = 0;i < this->count;i++)
	{
		std::cout << this->numbers[i] << " ";
	}
}

