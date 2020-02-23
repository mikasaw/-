
//插入排序
void insertionSort(int arr[], int size)
{
	int i , j, key;
	for (i = 0; i < size; i++)
	{
		j = i - 1;
		key = arr[i];
		while (j >= 0 && key <arr[j])      //遇到小的就把元素后移
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;		   //把值插入到空出来位置
	}
}
