



// 三分查找法  把数组分为三部分再持续递归查找下去
int ternarySearch(int l, int r, int key, int arr[])
{
	if (r >= 1)
	{
		int mid1 = l + (r - 1) / 3;
		int mid2 = r - (r - 1) / 3;
		
		if (arr[mid1] == key)
			return mid1;
		if (arr[mid2] == key)
			return mid2;

		if (key < arr[mid1])
			return ternarySearch(l, mid1 - 1, key, arr);
		else if (key > arr[mid2])
			return ternarySearch(mid2 + 1, r, key, arr);
		else
			return ternarySearch(mid1 + 1, mid2 + 1, key, arr);
	}
	return -1;
}
