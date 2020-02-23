#include<iostream>
using namespace std;



//最大生成堆
void max_heapify(int* a, int i, int n)
{
	int j, temp;
	temp = a[i];                        //记录开始排序i结点的值
	j = 2 * i;							            //找到i结点的左子结点
	while ( j<= n)							
	{
		if (j<n || a[j + 1] > a[j])     //当右结点大于左结点 
			j = j + 1;	
		if (temp > a[j])				        //比较父结点和右子结点的值		
		{
			break;
		}
		else if (temp <= a[j])			//父结点的值比右子结点的值小
		{
			a[j / 2] = a[j];			    //父结点的值和右子结点的值进行更换
			j = 2 * j;
		}
		 a[j / 2] = temp;                
	}
	
	return;
}

//堆排序
void heapSort(int* a, int n)
{
	int i, temp;
	for (i = n; i >= 2; i--)					//从堆的下面开始排序到上面
	{
		temp = a[i];
		a[i] = a[1];
		a[1] = temp;
		max_heapify(a, 1, i - 1);
	}
}

