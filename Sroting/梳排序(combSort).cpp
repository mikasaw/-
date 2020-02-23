
 
//梳排序 -- 在冒泡排序上进行优化的一种排序方法
#define SHRINK 1.3   //梳排序分组系数，1.2几最合适  一般取1.3
void combSort(int* numbers, int size)
{
	int gap = size;
	while (gap > 1)						          //直到不能再分组为止
	{
		gap = gap / SHRINK;
		int i = 0;
		while ((i+gap )< size)					  //把第一组和第二组的元素进行全部比较
		{
			if (numbers[i] > numbers[i + gap])                //第一组和第二组的元素进行比较，第一组
			{
				int tmp = numbers[i];			  //第一组比第二组大就进行交换
				numbers[i] = numbers[i + gap];
				numbers[i + gap] = tmp;
			}
			i++;
		}
	}
}
