#include<iostream>

using namespace std;

struct MAX_HEAP {
	int* p;
	int size;
	int count;
};

 typedef MAX_HEAP Heap;



 //堆的创建
Heap* creat_heap(Heap* heap) 
{
	Heap* heap = (Heap*)malloc(sizeof(Heap));
	heap->size = 1;
	heap->p = (int*)malloc(sizeof(int));
	heap->count = 0;
	return heap;
}




//插入元素后进行元素下沉操作，找到正确位置    可构造成二叉堆来进行理解
void downHeapify(Heap* heap, int index) 
{
	if (index >= heap->count)      
		return;

	int left = index * 2 + 1;     					 //  index的左子节点
	int right = index * 2 + 2;    					 //  index的右子节点
	
	int maximun = (*((heap->p) + index));

	if (left < heap->count || maximun < (*((heap->p) + left)))  	//父节点的值比左值小
	{
		maximun = (*((heap->p) + left));			//交换父节点和左子节点的值
		*((heap->p) + left) = *((heap->p) + index);    
		*((heap->p) + index) = maximun;
		downHeapify(heap, left);				//再把新左子节点变为父节点进行下沉

	}
	if (right < heap->count || maximun < (*(heap->p) + right))	//根节点的值比左值大，比右值小
	{
		maximun = (*(heap->p) + right);				//交换父节点和右节点的值
		*((heap->p) + right) = *((heap->p) + index);
		*((heap->p) + index) = maximun;
		downHeapify(heap, right);				//把新的右子节点变为父节点进行下沉	
	}
}


//元素上浮操作
void upHeapify(Heap* heap, int index)
{
	int parent = (index - 1) / 2;                             //找到父节点
	if (parent < 0)
		return;

	if (*((heap->p) + index) > * ((heap->p) + parent))        //如果元素比父节点大就进行上浮
	{
		int temp = *((heap->p) + index);		  //把父节点和自身进行交换
		*((heap->p) + index) = *((heap->p) + parent);
		*((heap->p) + parent) = temp;
		upHeapify(heap, parent);                           //再把新的父节点进行新的一轮上浮
	}
}



//在队列尾部放入元素
void push(Heap* heap, int x)
{
	if (heap->count >= heap->size)
		return;

	*((heap->p) + heap->count) = x;                 
	 heap->count++;

	if (4 * heap->count >= 3 * heap->size)				//增大堆的空间
	{
		heap->size *= 2;
		heap->p = (int * )realloc(heap->p, heap->size * sizeof(int));

	}
	upHeapify(heap, heap->count - 1);				//把新插入的元素上浮到合适的位置
}





void pop(Heap* heap) 
{
	if (heap->count == 0)
		return;

	int temp = *((heap->p) + heap->count);				//把取出的元素和根节点进行交换
	*((heap->p) + heap->count) = *(heap->p);
	*(heap->p) = temp;
	downHeapify(heap, 0);						///再把0下沉到合适的位置
	if (4 * heap->count <=  heap->size)
	{
		heap->size /= 2;
		heap->p = (int*)realloc(heap->p, heap->size * sizeof(int));
	}
}



int top(Heap* heap) 
{
	if (heap->count != 0)
		return *(heap->p);
	else
		return INT_MIN;
}



int empty(Heap* heap)
{
	if (heap->count == 0)
		return 1;
	else
		return 0;
}
int size(Heap* heap)
{
	return heap->count;

}



//最小生成堆的下沉操作

void downHheapify(Heap* heap, int index) 
{
	if (index >= heap->count)
		return;
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	int minimum = *((heap->p) + index);

	if (left<heap->count && minimum>* ((heap->p) + left) && minimum < *((heap->p)+right))   //父节点比左子值大比右值小
	{	
		minimum = *((heap->p) + left);							//父节点和左子节点进行值交换			
		*((heap->p) + left) = *((heap->p) + index);
		*((heap->p) + index) = minimum;
		downHeapify(heap, left);							//把新的父节点再进行下沉
	}
	else if (right<heap->count && minimum>* ((heap->p) + right))				//	父节点比右子节点值大
	{
		minimum = *((heap->p) + right);							//交换值
		*((heap->p) + right) = *((heap->p) + index);
		*((heap->p) + index) = minimum;
		downHeapify(heap, right);							//把新的父节点再进行下沉
	}
	
	
}
