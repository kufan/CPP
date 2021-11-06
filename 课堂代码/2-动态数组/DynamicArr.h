#pragma once


#define MYARRAY_TRUE  1
#define MYARRAY_FALSE 0

// ���һ��ֻ�ܱ��� int �������ݵĶ�̬����
typedef struct DYNAMICARR {
	int* pAddr;  // ָ�������������ݵ��ڴ�ռ�

	int capacity;  // ��������
	int size;      // ������Ԫ�ظ���
}DynamicArr;

DynamicArr* Init_Arr(int len);

// �������: ������ arr �� pos λ�ã�����һ�� val  
int Insert_Arr(DynamicArr* arr, int pos, int val);

// �ж������Ƿ�Ϊ��
int IsEmpty_Arr(DynamicArr* arr);

// ɾ��ָ��λ�õ�Ԫ��: ɾ������ arr �е�  pos λ�õ�Ԫ��
int DeleteByPos_Arr(DynamicArr* arr, int pos);


// Ѱ��ָ��Ԫ�ص�λ��
int Find_Arr(DynamicArr* arr, int val);

// ɾ��ָ��ֵ��Ԫ��
int DeleteByVal(DynamicArr* arr, int val);

// ���ָ��λ�õ�Ԫ��
int At_Arr(DynamicArr* arr, int pos);

// ��������
int Print_Arr(DynamicArr* arr);

// ���������
int GetCapacity_Arr(DynamicArr* arr);

// ������Ԫ�ظ���
int GetSize_Arr(DynamicArr* arr);

// ���
int Clear_Arr(DynamicArr* arr);

// ����
int Destroy_Arr(DynamicArr* arr);