#include<iostream>
using namespace std;

//打乱排序  如果数组是无序的，就一直打乱排序，直到有序为止。
void shuffSort(int* a ,int n)
{
  int flag = true;      //代表数组有序
  while(--n >= 1)
  {
    if (a[n-1]> a[n])
      flag = false;      //代表数组无序
    }
  while(!flag)           //进行排序
  {
      for (int i = 0; i < n; i++)
    	{
		    int r = rand() % n;
		    int t = a[i];
		    a[i] = a[r];
		    a[r] = t;
      }
  }
}
