


//地精排序:前进冒泡,一旦遇到冒泡的情况发生就往回冒,直到把这个数字放好为止.
void gnomeSort(int* numbers, int size)
{
	int i = 0;                                      // 当i为0时，先让其自增1，再进行排序
	while (i < size)
	{
		if (numbers[i] >= numbers[i - 1])       //不发生交换i 就自增1
			i++;
		else
		{
			int tmp = numbers[i - 1];        //发生交换i 就自减1
			numbers[i - 1] = numbers[i];
			numbers[i] = tmp;
			i--;
		}
		if (i == 0)
		i = 1;
	}
}
