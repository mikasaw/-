

void insertionSort(int arr[], int size)
{
	int i , j, key;
	for (i = 0; i < size; i++)
	{
		j = i - 1;
		key = arr[i];
		while (j >= 0 && key <arr[j])
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
