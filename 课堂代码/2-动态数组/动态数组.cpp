#include <iostream>

#include "DynamicArr.h"

using namespace std;

int main()
{
	DynamicArr* arr = Init_Arr(20);


	cout << "��ʼ����: " << GetCapacity_Arr(arr) << endl;
	cout << "��ʼԪ��: " << GetSize_Arr(arr) << endl;
	

	/*
	// �������: ������ arr �� pos λ�ã�����һ�� val
	int Insert_Arr(DynamicArr* arr, int pos, int val); 
	*/

	for (int i = 0; i < 30; i++) {
		Insert_Arr(arr, i, i + 1);
	}

	cout << "����֮������: " << GetCapacity_Arr(arr) << endl;
	cout << "����֮��Ԫ��: " << GetSize_Arr(arr) << endl;

	Print_Arr(arr);
	
	
	Destroy_Arr(arr);
	
	return 0;
}