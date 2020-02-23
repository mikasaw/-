#include<iostream>
using namespace std;



//基于二分查找法的插入排序
int binarySearch(int arr[], int key, int low, int high)
{
	if (low >= high)
		return (key > arr[low]) ? (low + 1) : low;
	int mid = low + (high - 1) / 2;
	if (arr[mid] == key)
		return mid + 1;
	else if (arr[mid] > key)						  //中间点的值比寻找的key值大
	{
		return binarySearch(arr, key, low, mid - 1);  //向中间的左边寻找

	}
	else
		return binarySearch(arr, key, mid + 1, high);  //否则向中间点的右边寻找
}

void insertionSort(int arr[], int size)
{
	int i, j, key, index;
	for (i = 1; i < size; i++)
	{
		j = i - 1;
		key = arr[i];
		index = binarySearch(arr, key, 0, j);    //在0到j直接找到key的位置
		while (j >= index)                       //找到值得位置比j小，把index和j之间所有元素都后移 
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;                        //再在index位置插入key值
	}
}
