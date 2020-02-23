
//数组反转操作
void filp(int arr[], int i)
{
	int temp, start = 0;
	while (start<i)
	{
		temp = arr[start];
		arr[start] = arr[i];
		arr[i] = temp;
		start++;
		i--;
	}
}


//进行反转排序
int pancakeSort(int* arr, int n)
{
	for (int curr_size = n; curr_size > 1; --curr_size)
	{
		//int maxElementIdx = findMax(arr, curr_size);
		int maxElementIdx = 0;
		for (int i = 0; i < curr_size; i++)                  //找到最大值得位置
			if (arr[i] > arr[maxElementIdx])
				maxElementIdx = i;

		if (maxElementIdx != curr_size - 1)
		{
			filp(arr, maxElementIdx);                     //进行递归反转数组
			filp(arr, curr_size - 1);
		}
	}
	return 1;
}

