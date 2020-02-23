

void shellSort(int array[], int len)
{
	int i, j, gap;

	for (gap = len / 2; gap > 0; gap = gap / 2)
		for (i = gap; i < len; i++)
			for (j = i - gap; j >= 0 && array[j] > array[j + gap]; j = j - gap)
					{
					    int temp = array[j];
					    array[j] = array[j + gap];
					    array[j + gap] = temp;
 					}

}
