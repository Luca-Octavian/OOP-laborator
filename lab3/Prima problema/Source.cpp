#include <iostream>
#include "Math.h"
using namespace std;
int main()
{
	Math M;
	const char s1[] = "Azi suntem la facultate";
	const char s2[] = " (din pacate ;-;)";
	cout << M.Add(2, 10) << '\n';
	cout << M.Add(10, 3, 40) << '\n';
	cout << M.Add(2.5, 3.532) << '\n';
	cout << M.Add(2.3, 3.7, 4.7) << '\n';
	cout << M.Mul(2, 5) << '\n';
	cout << M.Mul(2, 1, 4) << '\n';
	cout << M.Mul(3.15, 3.4, 4.7) << '\n';
	cout << M.Mul(2.2, 3.412) << '\n';
	cout << M.Add(5, 245, 2, 76, 4, 700) << '\n';
	cout << M.Add(s1, s2) << '\n';
	return 0;
}