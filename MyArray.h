#pragma once

#ifdef _cpulscpuls
 extern "C"{

#endif 

#define ARRAY_ERASED -1         //数组末尾
#define INVALID_POSITION 1      //无效的位置
#define POSITION_INIT 2         //初始化的位置
#define POSITION_NO_INIT 3      //没有初始化的位置
#define POSITION_IS_EMPTY 4        //位置为空
#define ARRAY_IS_FULL 5            //数组满
#define OUT_OF_RANGE 0           //位置超出范围

struct MyArray {

   int* array = NULL;
   int size = 0;

 };

 //数组的初始化
 MyArray* getArray(int size);
 MyArray* CopyArray(int* array);


//数组的输入和输出函数
int insertValueArray(MyArray* array, int position, int value);
int removeValueArray(MyArray* array, int position);
int pushValueArray(MyArray* array, int value);
int updateValueArray(MyArray* array, int position, int value);

 //数组删除操作
int eraseArray(MyArray* array);
int valueSwap(MyArray* array, int position1, int position2);

  
//数据转换操作
int switchValuesArray(MyArray* array, int position1, int position2);
int reverseArray(MyArray* array);





// 对数组进行排序操作
int bubbleSortArray(MyArray* array);
int selectionSortArray(MyArray* array);
int insertionSortArray(MyArray* array);
int blenderArray(MyArray* array);






//查找
int valueFindArray(MyArray* array, int value);
MyArray* valuePositionsArray(MyArray* array, int value);
int findMaxArray(MyArray* array);
int findMinArray(MyArray* array);




//显示
int displayArray(MyArray* array);