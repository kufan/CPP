#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "DynamicArr.h"


DynamicArr* Init_Arr(int len) {
	DynamicArr* arr = NULL;

	arr = (DynamicArr*)malloc(sizeof(DynamicArr));
	if (NULL == arr) {
		perror("malloc");
		return NULL;
	}

	arr->size     = 0;
	arr->capacity = len;

	arr->pAddr = (int*)malloc(sizeof(int) * len);
	if (NULL == arr->pAddr) {
		perror("malloc");
		return NULL;
	}

	// 把指针 arr->pAddr 所指向的，大小是 sizeof(arr->pAddr) 个 Byte 的内存空间
	// 全部初始化为 0
	memset(arr->pAddr, 0, sizeof(arr->pAddr));

	return arr;
}


// 插入操作: 在数组 arr 的 pos 位置，插入一个 val  
int Insert_Arr(DynamicArr* arr, int pos, int val) {
	if (NULL == arr) {
		return -1;
	}
	if (pos < 0 || pos > arr->size) {
		return -2;
	}

	if (arr->size == arr->capacity) {  // 数组满了，需要扩容
		// 1、开辟一块更大的空间(一般情况下，是原来空间的 2 倍)
		int* NewSpace = (int*)malloc(sizeof(int) * arr->capacity * 2);
		if (NULL == NewSpace) {
			perror("malloc");
			return -3;
		}
		
		// 2、将旧空间中的数据，拷贝到新开辟的空间中
		// void* memcpy(void* dest, const void* src, size_t n);
		// 把指针 src 所指向的，大小是 n 个字节的数据，拷贝到 dest 所指向的空间中
		// strcpy() --> 字符串拷贝，只能拷贝字符串
		memcpy(NewSpace, arr->pAddr, sizeof(int)*arr->capacity);
		
		// 3、释放旧的空间
		if (arr->pAddr != NULL) {
			free(arr->pAddr);
			arr->pAddr = NULL;
		}
		
		// 4、更新容量
		arr->capacity = arr->capacity * 2;
		arr->pAddr    = NewSpace;
	}

	// 执行插入操作
	// 此时数组中有  size 个元素，最后一个元素下标: size-1
	for (int i = arr->size - 1; i >= pos; i--) {
		arr->pAddr[i + 1] = arr->pAddr[i];
	}

	arr->pAddr[pos] = val;
	arr->size++;

	return 0;
}

// 判断数组是否为空
int IsEmpty_Arr(DynamicArr* arr) {
	if (NULL == arr) {
		return -1;
	}
	
	if (arr->size == 0) {
		return MYARRAY_TRUE;
	}

	return MYARRAY_FALSE;
}

// 删除指定位置的元素: 删除数组 arr 中第  pos 位置的元素
int DeleteByPos_Arr(DynamicArr* arr, int pos) {
	if (NULL == arr) {
		return -1;
	}
	if (pos < 0 || pos > arr->size) {
		return -2;
	}

	// 执行删除操作： 用后一个元素覆盖前一个元素
	for (int i = pos; i < arr->size; i++) {
		arr->pAddr[i] = arr->pAddr[i + 1];
	}
	arr->size--;  // 数组中元素少了一个

	return 0;
}


// 寻找指定元素的位置
int Find_Arr(DynamicArr* arr, int val) {
	if (NULL == arr) {
		return -1;
	}

	int pos = -2;
	for (int i = 0; i < arr->size; i++) {
		if (arr->pAddr[i] == val) {
			pos = i;   // 记录 val 的位置
			break; // 只关心第一个 val 的位置
		}
	}

	return pos;
}

// 删除指定值的元素
int DeleteByVal(DynamicArr* arr, int val) {
	if (NULL == val) {
		return -1;
	}

	int pos = Find_Arr(arr, val);
	if (pos < 0) {
		return pos;
	} else {
		DeleteByPos_Arr(arr, pos);
		return 0;
	}
}