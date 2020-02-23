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

	for (i = 0; i < len; i++)                 //把数组中的每个树都初始化为一串珠子，一个珠子代表1；             
	{
		for (j = 0; j < a[i]; j++)
		{
			BEAD(i, j) = 1;
		}
	}

	for (j = 0; j < max; j++)                  //让珠子往下落
	{
		for (sum = i = 0; i < len; i++)
		{
			sum += BEAD(i, j);
			BEAD(i, j) = 0;
		}
		for (i = len - sum; i < len; i++)
			BEAD(i, j) = 1;
	}
	for (i = 0; i < len; i++) 		   //下边有支点就保存不动
	{
		for (j = 0; j < max && BEAD(i, j); j++)
			a[i] = j;
	}
	free(beads);
}
