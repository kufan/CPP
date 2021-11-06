#include <iostream>

#include "DynamicArr.h"

using namespace std;

int main()
{
	DynamicArr* arr = Init_Arr(20);


	cout << "初始容量: " << GetCapacity_Arr(arr) << endl;
	cout << "初始元素: " << GetSize_Arr(arr) << endl;
	

	/*
	// 插入操作: 在数组 arr 的 pos 位置，插入一个 val
	int Insert_Arr(DynamicArr* arr, int pos, int val); 
	*/

	for (int i = 0; i < 30; i++) {
		Insert_Arr(arr, i, i + 1);
	}

	cout << "操作之后容量: " << GetCapacity_Arr(arr) << endl;
	cout << "操作之后元素: " << GetSize_Arr(arr) << endl;

	Print_Arr(arr);
	
	
	Destroy_Arr(arr);
	
	return 0;
}