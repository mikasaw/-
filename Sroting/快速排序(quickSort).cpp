


//快速排序先选择一个元素 把数组中比选择元素小的都移动到元素的前面去，比选择元素大的都移动到元素的后面去。
int partition(int arr[], int low, int high)
{
	int i = low - 1;
	int pivot = arr[high];				 //取上边界为选定元素

	int j;
	for (j = low; j < high; j++)      //从需要排序的范围中移动元素
	{
		if (arr[j] <= pivot)             //值比选定的元素的值小，就移动到前面
		{
			i++;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	int temp = arr[i + 1];              //重新把选取的元素放回开始的位置
	arr[i + 1] = arr[high];
	arr[high] = temp;
	
	return (i + 1);
}

//进行位置调整的第二种方法
int partition2(int arr[], int low, int high) {
	int key;
	key = arr[low];
	while (low < high)							//循环比较
	{
		while (low < high && arr[high] >= key)
			high--;
		if (low < high)
			arr[low++] = arr[high];
		while (low < high && arr[low] <= key)
			low++;
		if (low < high)
			arr[high--] = arr[low];
	}
	arr[low] = key;
	return low;
}


void quickSort(int arr[], int low, int high)
{
	if (high > low)
	{
		int partitionIndex = partition(arr, low, high);  //找到中间元素位置
		quickSort(arr, low, partitionIndex);				//在分别对两边进行递快速排序
		quickSort(arr, partitionIndex + 1, high);
	}
}
