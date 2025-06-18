#include "pch.h"
#include "quick_sort.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}
TEST(Testpartitionare, partitionare)
{
	int v[10];
	v[0] = 3;
	v[1] = 1;
	v[2] = 2;
	v[3] = 5;
	v[4] = 4;
	int g[10];
	g[0] = 1;
	g[1] = 2;
	g[2] = 3;
	g[3] = 4;
	g[4] = 5;
	int n = 5, i;
	int k = quick_sort<int>::partition(v, 0, n - 1);
	EXPECT_EQ(k, 2);
} 
TEST(Testsortare, quicksort)
{
	int v[10];
	v[0] = 3;
	v[1] = 1;
	v[2] = 2;
	v[3] = 5;
	v[4] = 4;
	int g[10];
	g[0] = 1;
	g[1] = 2;
	g[2] = 3;
	g[3] = 4;
	g[4] = 5;
	int n = 5, i;
	quick_sort<int>::QuickSort(v, 0, n - 1);
	for (int i = 0;i < 5;i++)
		EXPECT_EQ(v[i], g[i]);
}