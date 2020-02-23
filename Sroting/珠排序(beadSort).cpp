#include<iostream>
using namespace std;
void beadSort(int* a, int len)			  //a -- 要排序的数组   len--为数组的大小
{
	int i, j, max, sum;
	unsigned char* beads;
	#define BEAD(i,j)beads[i*max+j]           //用一位数组来模拟二维数组

	for (i = 1, max = a[0]; i < len; i++)	  //找出数组的最大值
	{
		if (a[i] > max)
			max = a[i];
	}

	beads = static_cast<unsigned char*>(calloc(1, max * len));

	for (i = 0; i < len; i++)
	{
		for (j = 0; j < a[i]; j++)
		{
			BEAD(i, j) = 1;
		}
	}

	for (j = 0; j < max; j++)
	{
		for (sum = i = 0; i < len; i++)
		{
			sum += BEAD(i, j);
			BEAD(i, j) = 0;
		}
		for (i = len - sum; i < len; i++)
			BEAD(i, j) = 1;
	}
	for (i = 0; i < len; i++)
	{
		for (j = 0; j < max && BEAD(i, j); j++)
			a[i] = j;
	}
	free(beads);
}
