#pragma once

#ifdef _cpulscpuls
 extern "C"{

#endif 

#define ARRAY_ERASED -1         //����ĩβ
#define INVALID_POSITION 1      //��Ч��λ��
#define POSITION_INIT 2         //��ʼ����λ��
#define POSITION_NO_INIT 3      //û�г�ʼ����λ��
#define POSITION_IS_EMPTY 4        //λ��Ϊ��
#define ARRAY_IS_FULL 5            //������
#define OUT_OF_RANGE 0           //λ�ó�����Χ

struct MyArray {

   int* array = NULL;
   int size = 0;

 };

 //����ĳ�ʼ��
 MyArray* getArray(int size);
 MyArray* CopyArray(int* array);


//�����������������
int insertValueArray(MyArray* array, int position, int value);
int removeValueArray(MyArray* array, int position);
int pushValueArray(MyArray* array, int value);
int updateValueArray(MyArray* array, int position, int value);

 //����ɾ������
int eraseArray(MyArray* array);
int valueSwap(MyArray* array, int position1, int position2);

  
//����ת������
int switchValuesArray(MyArray* array, int position1, int position2);
int reverseArray(MyArray* array);





// ����������������
int bubbleSortArray(MyArray* array);
int selectionSortArray(MyArray* array);
int insertionSortArray(MyArray* array);
int blenderArray(MyArray* array);






//����
int valueFindArray(MyArray* array, int value);
MyArray* valuePositionsArray(MyArray* array, int value);
int findMaxArray(MyArray* array);
int findMinArray(MyArray* array);




//��ʾ
int displayArray(MyArray* array);