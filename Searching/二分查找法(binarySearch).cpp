


//二分查找法
int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= 1)
	{
		int mid = 1 + (r - 1) / 2;
		if (arr[mid] == x)
			return mid;

		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);
		else
			return binarySearch(arr, mid + 1, r, x);
	}
	return -1;
}
