#include<iostream>
using namespace std;


//桶排序1  用一个辅助的桶来帮助排序
int* buckerSort1(int arr[], int size)
{
	int* val =static_cast<int*>( malloc(sizeof(int*) * size));
	
	for (int  i = 0; i < size; i++)            //把数组的数值取出放入相应的桶中
	{
		val[arr[i]] = arr[i];

	}
	for (int i = 0; i < size; i++)            //在把排序后的值从新放回数组
	{
		arr[i] = val[i];
	}
	return arr;
}




//桶排序2
#define NARRAY 8    //数组大小
#define NBUCKET 5   //桶的大小
#define INTERVAL  10   // 桶的范围
struct Node
{
	int data;           
	struct Node* next;
};

struct Node* InsertionSort( Node* list)
{
	struct Node* k,* nodelist;
	if (list == NULL || list->next == NULL)   //链表为空
		return list;

	nodelist = list;                          //头结点
	k = list->next;							
	nodelist->next = NULL;
	while (k!= NULL)
	{
		struct Node* ptr;
		if (nodelist->data > k->data)            //如果前一个结点的值大于后一个结点，就交换位置
		{
			struct Node* tmp;
			tmp = k;
			k = k->next;
			tmp->next = nodelist;
			nodelist = tmp;
			continue;
		}
		for (ptr = nodelist; ptr->next != NULL; ptr = ptr->next) //遍历链表查看是否有序
		{
			if (ptr->next->data > k->data)  
				break;
		
			if (ptr->next != NULL)          
			{
				struct Node* tmp;
				tmp = k;
				k = k->next;
				tmp->next = ptr->next;
				ptr->next = tmp;
				continue;
			}
			else               
			{
				ptr->next = k;
				k = k->next;
				ptr->next->next = NULL;
				continue;
			}
		}
	}



	return nodelist;

}

void BuckerSort(int arr[])
{
	int i = 0, j = 0;
	struct Node** buckerts;               //辅助桶数组 用来记录从圆桶取出的数据
	buckerts = static_cast<struct Node**>(malloc(sizeof(struct Node*) * NBUCKET));

	for (i; i < NBUCKET; i++)             //把辅助桶初始化
	{
		buckerts[i] = NULL;
	}

	for (i; i < NARRAY; i++)              //把数组中的每个元素都放到辅助桶的合适位置上
	{
		struct Node* current;
		int pos = i%INTERVAL;
		current = static_cast<struct Node*>(malloc(sizeof(struct Node)));
		current->data = arr[i];
		current->next = buckerts[pos];
		buckerts[pos] = current;
	}
	for (i = 0; i < NBUCKET; i++)          //把排序后的桶重新放回辅助桶里
	{
		buckerts[i] = InsertionSort(buckerts[i]);
	}

	for (j, i; i < NBUCKET; i++)           //原数组重新记录排序后的数据
	{
		struct Node* node;
		node = buckerts[i];
		while (node)
		{
			if (j > NARRAY)
				return;
			arr[j++] = node->data;
			node = node->next;

		}
	}

	for (i; i < NBUCKET; i++)               //释放生成的结点
	{
		struct Node* node;
		node = buckerts[i];
		while (node)
		{
			struct Node* tmp;
			tmp = node;
			node = node->next;
			free(tmp);
		}
	}

	free(buckerts);                 
	return;
	
}
