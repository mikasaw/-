

//漂亮排序法
void stoogeSort(int arr[], int i, int j)
{
	if (arr[i] > arr[j])
	{
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}  
	if ((i + 1) >= j)
		return;
	int k = static_cast<int >((j - i + 1) / 3); 
	stoogeSort(arr, i, j - k);              //先排序前2/3部分
	stoogeSort(arr, i + k, j);				      //再排序后2/3部分
	stoogeSort(arr, i , j - k);				      //最后进行前面1/3的排序
}
