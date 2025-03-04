#include <iostream>
#include "NumberList.h"
using namespace std;
int main()
{
	NumberList L;
	L.Init();
	L.Add(7);
	L.Add(90);
	L.Add(20);
	L.Print();
	L.Sort();
	L.Print();
	return 0;

}