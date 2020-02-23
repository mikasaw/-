#include<iostream>
using namespace std;


void bubbleSort(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for(int j =0;j<size-1;i++)
			if (arr[i] > arr[j + 1])
			{
				int temp = arr[i];
				arr[i] = arr[j + 1];
				arr[j + 1] = temp;
	  	}
	}
}


