


//线性查找法 遍历数组每个元素寻找值
int linearSearch(int* arr, int size, int val)
{
	int i = 0;
	for (i; i < size; i++)
	{
		if (arr[i] == val)
			return 1;
	}
	return 0;
}
