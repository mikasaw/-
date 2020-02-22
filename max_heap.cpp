#include<iostream>

using namespace std;

struct MAX_HEAP {
	int* p;
	int size;
	int count;
};

 typedef MAX_HEAP Heap;



 //�ѵĴ���
Heap* creat_heap(Heap* heap) 
{
	Heap* heap = (Heap*)malloc(sizeof(Heap));
	heap->size = 1;
	heap->p = (int*)malloc(sizeof(int));
	heap->count = 0;
	return heap;
}




//����Ԫ�غ����Ԫ���³��������ҵ���ȷλ��    �ɹ���ɶ�������������
void downHeapify(Heap* heap, int index) 
{
	if (index >= heap->count)      
		return;

	int left = index * 2 + 1;      //  index�����ӽڵ�
	int right = index * 2 + 2;     //  index�����ӽڵ�
	
	int maximun = (*((heap->p) + index));

	if (left < heap->count || maximun < (*((heap->p) + left)))  //���ڵ��ֵ����ֵС
	{
		maximun = (*((heap->p) + left));						//�������ڵ�����ӽڵ��ֵ
		*((heap->p) + left) = *((heap->p) + index);    
		*((heap->p) + index) = maximun;
		downHeapify(heap, left);								//�ٰ������ӽڵ��Ϊ���ڵ�����³�

	}
	if (right < heap->count || maximun < (*(heap->p) + right))	//���ڵ��ֵ����ֵ�󣬱���ֵС
	{
		maximun = (*(heap->p) + right);							//�������ڵ���ҽڵ��ֵ
		*((heap->p) + right) = *((heap->p) + index);
		*((heap->p) + index) = maximun;
		downHeapify(heap, right);								//���µ����ӽڵ��Ϊ���ڵ�����³�	
	}
}


//Ԫ���ϸ�����
void upHeapify(Heap* heap, int index)
{
	int parent = (index - 1) / 2;                             //�ҵ����ڵ�
	if (parent < 0)
		return;

	if (*((heap->p) + index) > * ((heap->p) + parent))        //���Ԫ�رȸ��ڵ��ͽ����ϸ�
	{
		int temp = *((heap->p) + index);					  //�Ѹ��ڵ��������н���
		*((heap->p) + index) = *((heap->p) + parent);
		*((heap->p) + parent) = temp;
		upHeapify(heap, parent);                              //�ٰ��µĸ��ڵ�����µ�һ���ϸ�
	}
}



//�ڶ���β������Ԫ��
void push(Heap* heap, int x)
{
	if (heap->count >= heap->size)
		return;

	*((heap->p) + heap->count) = x;                 
	 heap->count++;

	if (4 * heap->count >= 3 * heap->size)						//����ѵĿռ�
	{
		heap->size *= 2;
		heap->p = (int * )realloc(heap->p, heap->size * sizeof(int));

	}
	upHeapify(heap, heap->count - 1);							//���²����Ԫ���ϸ������ʵ�λ��
}





void pop(Heap* heap) 
{
	if (heap->count == 0)
		return;

	int temp = *((heap->p) + heap->count);						//��ȡ����Ԫ�غ͸��ڵ���н���
	*((heap->p) + heap->count) = *(heap->p);
	*(heap->p) = temp;
	downHeapify(heap, 0);										///�ٰ�0�³������ʵ�λ��
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



//��С���ɶѵ��³�����

void downHheapify(Heap* heap, int index) 
{
	if (index >= heap->count)
		return;
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	int minimum = *((heap->p) + index);

	if (left<heap->count && minimum>* ((heap->p) + left) && minimum < *((heap->p)+right))   //���ڵ������ֵ�����ֵС
	{	
		minimum = *((heap->p) + left);						//���ڵ�����ӽڵ����ֵ����			
		*((heap->p) + left) = *((heap->p) + index);
		*((heap->p) + index) = minimum;
		downHeapify(heap, left);							//���µĸ��ڵ��ٽ����³�
	}
	else if (right<heap->count && minimum>* ((heap->p) + right))	//	���ڵ�����ӽڵ�ֵ��
	{
		minimum = *((heap->p) + right);								//����ֵ
		*((heap->p) + right) = *((heap->p) + index);
		*((heap->p) + index) = minimum;
		downHeapify(heap, right);									//���µĸ��ڵ��ٽ����³�
	}
	
	
}