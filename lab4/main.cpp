#include <iostream>
using namespace std;
#include "Sort.h"
using namespace std;
int main()
{
	const int vec2[6] = {10, 2, 3, 7, 50, 6};
	Sort v1( 10,50,70 );
	Sort v2{ 20,60,80,40,20,30,10,70,89 };
	Sort v3( "30,40,50,120,5,6,3" );
	Sort v4( 5,1,3,6,7,4 );
	Sort v5(vec2, 6);
	v1.BubbleSort(false);
	v1.Print();
	v2.Print();
	v3.Print();
	v4.Print();
	v5.Print();


	


}