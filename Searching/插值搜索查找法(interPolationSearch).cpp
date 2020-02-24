



// 插值搜索算法
int interPolationSearch(int arr[], int n, int key)
{
	int low = 0, high = n - 1;
	while (low<= high && key >= arr[low] && key<= arr[high])
	{
		//用线性函数来计算出最可能接近的位置 (函数可由自己来设定)
		int pos = low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);
		if (key > arr[pos])
			low = pos + 1;
		else if (key < arr[pos])
			high = pos - 1;
		else
			return pos;

	}
	return -1;
}
