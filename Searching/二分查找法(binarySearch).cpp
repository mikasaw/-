


//二分查找法
int binarySearch1(int arr[], int l, int r, int x)
{
	if (r >= 1)
	{
		int mid = 1 + (r - 1) / 2;
		if (arr[mid] == x)
			return mid;

		if (arr[mid] > x)
			return binarySearch1(arr, l, mid - 1, x);
		else
			return binarySearch1(arr, mid + 1, r, x);
	}
	return -1;
}



int binarySearch2(int array[], int leng, int X)
{
	int pos = -1 ,right, left, i = 0;
	left = 0;
	right = leng - 1;

	while (left<= right)
	{
		pos = left + (right - left) / 2;		 // 找到中间的位置
		if (array[pos] == X)
			return pos;
		else if (array[pos] > X)			 //pos位置的值比寻找的x大，右边范围减一
		{
			right = pos - 1;
		}
		else						 //pos位置的值比寻找的x小，左边范围减一
		{
			left = pos + 1;
		}

	}
	return -1;
}
