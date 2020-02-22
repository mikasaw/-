// CArray.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//主要实现了一些简单的数组算法



#include <iostream>
#include "CArray.h"
#include<time.h>
using namespace std;

// 
 //数组的初始化
 //
MyArray* getArray(int size) {
	int i = 0;
	//MyArray* array = (MyArray*)malloc(sizeof(MyArray));
	MyArray* array = new MyArray;
	array->array = (int*)malloc(sizeof(MyArray) * size);
	array->size = size;
	for ( i ;i<size;i++) 
	{
		array->array[i] = { 0 };
	}

	return array;

}//数组的拷贝
MyArray* CopyArray(int* array)
{
	MyArray* newArray = new MyArray;
	newArray->array = (int*)malloc(sizeof(array));
	for (int i = 0; i < sizeof(array); i++) {
		newArray->array[i] = array[i];
	}
	return newArray;
}

//数组的值交换
int valueSwap(MyArray* array, int position1, int position2)
{
	int temp = 0;
	temp = array->array[position1];
	array->array[position1] = array->array[position2];
	array->array[position2] = temp;
	return 1;
}

//值插入操作
int insertValueArray(MyArray* array, int position, int value) {
	if (sizeof(array->array) == array->size)
		return ARRAY_IS_FULL;
	if (position > 0 && position < array->size)
	{
		if (array->array[position] == 0)  //原本位置中没有数据，直接赋值
		{
			array->array[position] == value;
			return 1;
		}
		else {   //有数据，位置后面的数据后移一位；
			for (int i = array->size; i >position ; i--) {
				array->array[i + 1] = array->array[i];
			}
			array->array[position] = value;
		}
	}
	else
	{
		return INVALID_POSITION;
	}
	return 1;
}


 
//值删除操作
int removeValueArray(MyArray* array, int position) {
	if (position > 0 || position < array->size)
	{
		if (array->array[position] != 0)
			array->array[position] = 0;
		else
			return POSITION_IS_EMPTY;
	}
	else
	{
		return INVALID_POSITION;
	}
	return POSITION_NO_INIT;

	
}
//在数组末尾添加值
int pushValueArray(MyArray* array, int value) {
	if (array->size < sizeof(array->array))
	{
		for (int i = 0; i < array->size; i++)
		{
			if (array->array[i] == 0)
			{
				array->array[i] = value;
					return 1;
			}
		}

	}
	return ARRAY_IS_FULL;
	

}



//更新数值
int updateValueArray(MyArray* array, int position, int value) {
	if (position > 0 || position < array->size) {
		
		array->array[position] = value;
		return 1;
	}

	return INVALID_POSITION;


}




// 数组删除
int eraseArray(MyArray* array)
{
	for (int i = 0; i < array->size; i++)
	{
		array->array[i] = 0;
	}
	return 1;
}



 //数值转换
int switchValuesArray(MyArray* array, int position1, int position2)
{
	
	if (position1 > 0 || position2 > 0 || position1 < sizeof(array->array) || position2 < sizeof(array->array))
	{
		int temp = 0;
		temp = array->array[position1];
		array->array[position1] = array->array[position2];
		array->array[position2] = temp;
		return 1;
	}
	return INVALID_POSITION;

}

//数组反转
int reverseArray(MyArray* array) {
	int p1 = 0, p2 = 0;
	for (int i = 0; i < array->size / 2; i++)
	{
		p1 = array->array[i];
		p2 = array->array[array->size-i];
		array->array[i] = p2;
		array->array[array->size - i] = p1;
		break;
	}
	return 1;

}





// 排序算法
//冒泡排序
int bubbleSortArray(MyArray* array) {
	int i = 0;
	for (i; i < array->size; i++)
	{
		if (array->array[i] > array->array[i + 1])  //前后两个元素进行比较，并把大的值放到后面
		{
			swap(array->array[i] ,array->array[i + 1]);
		}
	}
	return 1;

}
//选择排序
int selectionSortArray(MyArray* array)
{
	int i = 0, j = 0, min = array->array[i];
	for (i; i < array->size; i++)
	{
		for(j=i+1;j<array->size;j++)
		if (array->array[j] < min)    //把接下来队列中的最小值找出来
		{
			
			min =array->array[j];
		}
		int temp = array->array[i];      //把找出来的最小值放到前面
		array->array[i] = array->array[j];
		array->array[j] = temp;

	}
	return 1;
}

//插入排序法
int insertionSortArray(MyArray* array) {
	int i = 1, j = 0, min = 0;
	for (i; i < array->size; i++)
	{
		min = array->array[i];
		j = i - 1;
		while (j >= 0 || array->array[j] > min)   //把比比较元素大的全部后移一位
		{
			array->array[j + 1] = array->array[j];
			j--;
		}
		array->array[j] = min;   //插入元素
	}
	return 0;
}

//搅拌法 把数组变成无序
int blenderArray(MyArray* array)
{
	srand(time(NULL) * array->size);
	int i = 0;
	for (i; i < array->size * 100; i++) {
		valueSwap(array, rand() % array->size, rand() % array->size);
	}
	return 0;


}




//查找数组中一个值的个数
int valueFindArray(MyArray* array, int value) {
	int total = 0;
	for (int i = 0; i < array->size; i++)
	{
		if (array->array[i] == value)
			total++;
	}
	return total;
}



MyArray* valuePositionsArray(MyArray* array, int value)
{
	int total = 0;
	total = valueFindArray(array, value);
	MyArray* findArray = getArray(total);
	for (int i = 0; i <total; i++)
	{
		findArray->array[i] = value;
	}
	findArray->size = total;
	return findArray;

}




//找到最大值
int findMaxArray(MyArray* array) {
	
	bubbleSortArray(array);
	return array->array[array->size];
}



//找到最小值
int findMinArray(MyArray* array) {
	bubbleSortArray(array);
	return array->array[0];
}




//显示整个数组
int displayArray(MyArray* array) {
	for (int i = 0; i < array->size; i++)
	{
		cout << array->array[i];
	}
	return 1;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
