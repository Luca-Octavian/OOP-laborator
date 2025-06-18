#include <iostream>
#include <cstdarg>
#include <cstring>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
using namespace std;
#include "Sort.h"
int Sort::GetElementsCount()
{
	return this->count;
}
int Sort::GetElementFromIndex(int index)
{
	return this->v[index];
}
void Sort::InsertSort(bool ascendent)
{
	int n = GetElementsCount();
	for (int i = 1;i < n;i++)
	{
		int key = GetElementFromIndex(i);
		for (int j = i - 1;j >= 0&&GetElementFromIndex(j)>key;j--)
		{
			v[j + 1] = v[j];
		}
	}
}
void Sort::BubbleSort(bool ascendent)
{
	int n = GetElementsCount();
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			if (GetElementFromIndex(i) > GetElementFromIndex(j))
			{
				int aux = this->v[i];
				this->v[i] = this->v[j];
				this->v[j] = aux;
			}
		}
	}
}
int Sort::partitie(int low, int high)
{
	int pivot = GetElementFromIndex(high);
	cout << pivot;
	int i = low + 1;
	for (int j = low;j <= high;j++)
	{
		if (GetElementFromIndex(j) < pivot)
		{
			i++;
			int aux = this->v[i];
			this->v[i] = this->v[j];
			this->v[j] = aux;
		}
	}
	int aux2 = this->v[i+1];
	this->v[i+1] = this->v[high];
	this->v[high] = aux2;
	return i + 1;
}
void Sort::QuickSort(bool ascendent)
{
	int n = GetElementsCount();
	quicksortcorect(0, n-1);
}
void Sort::quicksortcorect(int low, int high)
{
	if (low < high)
	{
		int index = partitie(low, high);
		quicksortcorect(low, index + 1);
		quicksortcorect(index - 1, high);
	}
}
Sort::Sort(initializer_list<int> L)
{
	this->count = L.size();
	this->v = new int[L.size()];
	int j = 0;
	for (int i : L) //for each operator
	{
		this->v[j] = i;
		j++;
	}
	
}
Sort::Sort(int count, int min, int max)
{
	srand(time(NULL));
	this->count = count;
	this->v = new int[count];
	for (int i = 0;i < count;i++)
	{
		this->v[i] = rand() % max + min;
	}
}
Sort::Sort(const int* vec2, int count2)
{
	this->count = count2;
	this->v = new int[count2];
	memcpy(this->v, vec2, count2 * sizeof(int));
	
}
Sort::Sort(int count, ...)
{
	this->count = count;
	this->v = new int[this->count];
	va_list a;
	va_start(a, count);
	for (int i = 0;i < count;i++)
	{
		this->v[i] = va_arg(a, int);
	}
}
Sort::Sort(const char* str)
{
	int numbers = 0;
	
	for (int i = 0;str[i];i++)
	{
		if (str[i] == ',')
			numbers++;
	}
	this->v = new int[numbers+1];
	this->count = numbers;
	int j = 0;
	
	for (int i = 0;i<=numbers;i++)
	{
		int num = 0;
		while (str[j] != ',' && str[j])
		{
			num = num * 10 + str[j] - '0';
			j++;
		}
		j++;
		this->v[i] = num;
	}
	
}

void Sort::Print()
{
	for (int i = 0;i < this->count;i++)
	{
		cout << this->v[i] << " ";
		
	}
	cout << endl;
}