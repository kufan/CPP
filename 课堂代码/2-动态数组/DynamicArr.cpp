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

	// ��ָ�� arr->pAddr ��ָ��ģ���С�� sizeof(arr->pAddr) �� Byte ���ڴ�ռ�
	// ȫ����ʼ��Ϊ 0
	memset(arr->pAddr, 0, sizeof(arr->pAddr));

	return arr;
}


// �������: ������ arr �� pos λ�ã�����һ�� val  
int Insert_Arr(DynamicArr* arr, int pos, int val) {
	if (NULL == arr) {
		return -1;
	}
	if (pos < 0 || pos > arr->size) {
		return -2;
	}

	if (arr->size == arr->capacity) {  // �������ˣ���Ҫ����
		// 1������һ�����Ŀռ�(һ������£���ԭ���ռ�� 2 ��)
		int* NewSpace = (int*)malloc(sizeof(int) * arr->capacity * 2);
		if (NULL == NewSpace) {
			perror("malloc");
			return -3;
		}
		
		// 2�����ɿռ��е����ݣ��������¿��ٵĿռ���
		// void* memcpy(void* dest, const void* src, size_t n);
		// ��ָ�� src ��ָ��ģ���С�� n ���ֽڵ����ݣ������� dest ��ָ��Ŀռ���
		// strcpy() --> �ַ���������ֻ�ܿ����ַ���
		memcpy(NewSpace, arr->pAddr, sizeof(int)*arr->capacity);
		
		// 3���ͷžɵĿռ�
		if (arr->pAddr != NULL) {
			free(arr->pAddr);
			arr->pAddr = NULL;
		}
		
		// 4����������
		arr->capacity = arr->capacity * 2;
		arr->pAddr    = NewSpace;
	}

	// ִ�в������
	// ��ʱ��������  size ��Ԫ�أ����һ��Ԫ���±�: size-1
	for (int i = arr->size - 1; i >= pos; i--) {
		arr->pAddr[i + 1] = arr->pAddr[i];
	}

	arr->pAddr[pos] = val;
	arr->size++;

	return 0;
}

// �ж������Ƿ�Ϊ��
int IsEmpty_Arr(DynamicArr* arr) {
	if (NULL == arr) {
		return -1;
	}
	
	if (arr->size == 0) {
		return MYARRAY_TRUE;
	}

	return MYARRAY_FALSE;
}

// ɾ��ָ��λ�õ�Ԫ��: ɾ������ arr �е�  pos λ�õ�Ԫ��
int DeleteByPos_Arr(DynamicArr* arr, int pos) {
	if (NULL == arr) {
		return -1;
	}
	if (pos < 0 || pos > arr->size) {
		return -2;
	}

	// ִ��ɾ�������� �ú�һ��Ԫ�ظ���ǰһ��Ԫ��
	for (int i = pos; i < arr->size; i++) {
		arr->pAddr[i] = arr->pAddr[i + 1];
	}
	arr->size--;  // ������Ԫ������һ��

	return 0;
}


// Ѱ��ָ��Ԫ�ص�λ��
int Find_Arr(DynamicArr* arr, int val) {
	if (NULL == arr) {
		return -1;
	}

	int pos = -2;
	for (int i = 0; i < arr->size; i++) {
		if (arr->pAddr[i] == val) {
			pos = i;   // ��¼ val ��λ��
			break; // ֻ���ĵ�һ�� val ��λ��
		}
	}

	return pos;
}

// ɾ��ָ��ֵ��Ԫ��
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