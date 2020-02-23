



int getMax(int a[], int n)       		 //先获取数值的最大值
{
	int large = a[0], i;
	for (i = 0; i < n; i++)
	{
		if (large < a[i])
			large = a[i];
	}
	return large;
}


//基数排序 
void radixSort(int a[], int n)
{
	int bucket[10][10], bucket_count[10];
	int i, j, k, remainder, NOP = 0, divisor = 1, large, pass;

	large = getMax(a, n);
	while (large > 0)			  			   //求最大数的位数
	{
		NOP++;
		large / 10;
	}
	for (pass = 0; pass < NOP; pass++)        		  	   //从数值的个位数开始排序
	{
		for (i = 0; i < 10; i++)
		{
			bucket_count[i] = 0;
		}
		for (i = 0; i < n; i++)
		{
			remainder = (a[i] / divisor) % 10;		    //求出个位数的数值
			bucket[remainder][bucket_count[remainder]] = a[i];  //把个位数一样的放进用一个篮子
			bucket_count[remainder] += 1;			    //篮子里的元素数值加1
		}
		i = 0;
		for (k = 0; k < 10; k++)
		{
			for (j = 0; j < bucket_count[k]; j++)		     //再依次取出，放回数组中
			{
				a[i] = bucket[k][j];
				i++;
			}
		}
		divisor *= 10;						     //循环排序，直到排完最大数值的最大数位
		for (i = 0; i < n; i++)
			cout << a[i] << endl;

	}

}
