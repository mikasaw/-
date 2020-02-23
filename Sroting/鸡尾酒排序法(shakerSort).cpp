


	void swap(int a, int b)
	{
		int t = a;
		 a = b;
		 b = t;
	}
  
  
//鸡尾酒排序法：先让气泡排序由左向右进行，再来让气泡排序由右往左进行，如此完成一次排序的动作
void shakerSort(int a[], int n)
{
	int p, i;
	for (p = 1; p <= n / 2; p++)
	{
		for (i = p - 1; i < n - p; i++)         //先由左向右冒泡排序(大值向右冒泡)
			if (a[i] > a[i + 1])					
				swap1(a[i], a[i + 1]);
		for (i = n - p - 1; i >= p; i--)		//再由右到左冒泡排序(小值向左冒泡)
		{
			if (a[i] < a[i - 1])
			{
				swap1(a[i], a[i + 1]);
			}
		}
	}

}
