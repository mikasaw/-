


//斐波那契查找法 --- 对于斐波那契数列，在关键点右边元素的个数个数为F(2K-2)个，在左边的元素的个数为F(2K-1)个
		
int fibMonaccianSearch(int arr[], int x, int n)
{
	int low = 0;
	int high = n - 1;
	int k = 0;

	int* F = static_cast<int*> (malloc(sizeof(int*) * n));  //构造一个斐波那契数列
	F[0] = 0;
	F[1] = 1;
	for (int i = 0; i < n; i++)
	{
		F[i] = F[i - 1] + F[i - 2];
	}

	while (n > F[k] - 1)    //计算n位于斐波那契数列的位置
		++k;

	int* temp;              //将数组a扩展到F[k]-1的长度
	temp = new int[F[k] - 1];
	for (int i = n; i < F[k] - 1; ++i)
		 temp[i] = F[n - 1];

	while (low <= high)
	{
		int mid = low + F[k - 1] - 1;
		if (x < temp[mid])
		{
			high = mid - 1;
			k -= 1;
		}
		else if (x > temp[mid])
		{
			low = mid + 1;
			k -= 2;
		}
		else
		{
			if (mid < n)
				return mid;   //若相等则说明mid即为查找到的位置
			else
				return n - 1; //若mid>=n则说明是扩展的数值,返回n-1
		}
	}
	delete[] temp;
	return -1;
}

