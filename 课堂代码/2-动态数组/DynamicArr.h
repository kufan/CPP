#pragma once


#define MYARRAY_TRUE  1
#define MYARRAY_FALSE 0

// 设计一个只能保存 int 类型数据的动态数组
typedef struct DYNAMICARR {
	int* pAddr;  // 指向真正保存数据的内存空间

	int capacity;  // 数组容量
	int size;      // 数组中元素个数
}DynamicArr;

DynamicArr* Init_Arr(int len);

// 插入操作: 在数组 arr 的 pos 位置，插入一个 val  
int Insert_Arr(DynamicArr* arr, int pos, int val);

// 判断数组是否为空
int IsEmpty_Arr(DynamicArr* arr);

// 删除指定位置的元素: 删除数组 arr 中第  pos 位置的元素
int DeleteByPos_Arr(DynamicArr* arr, int pos);


// 寻找指定元素的位置
int Find_Arr(DynamicArr* arr, int val);

// 删除指定值的元素
int DeleteByVal(DynamicArr* arr, int val);

// 获得指定位置的元素
int At_Arr(DynamicArr* arr, int pos);

// 遍历数组
int Print_Arr(DynamicArr* arr);

// 数组的容量
int GetCapacity_Arr(DynamicArr* arr);

// 数组中元素个数
int GetSize_Arr(DynamicArr* arr);

// 清空
int Clear_Arr(DynamicArr* arr);

// 销毁
int Destroy_Arr(DynamicArr* arr);