#include<iostream>

using namespace std;

template<class T>
class quick_sort
{
public:
	static int partition(T* v, int st, int dr)
	{
		int k = st;
		T x = v[k];
		T aux;
		int i = st + 1;
		int j = dr;
		while (i < j)
		{
			if (v[i] < x) //<=
				i++;
			if (v[j] > x)
				j--;
			if (v[i] > x && v[j] < x && i <= j)
			{

				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
				i++;
				j--;
			}
		}
		aux = v[k];
		v[k] = v[i - 1];
		v[i - 1] = aux;
		k = i;
		return k;
	}
	static void QuickSort(T* v, int st, int dr)
	{
		if (st < dr)
		{
			int k = partition(v, st, dr);
			QuickSort(v, st, k - 1);
			QuickSort(v, k, dr); //
		}
	}
};



