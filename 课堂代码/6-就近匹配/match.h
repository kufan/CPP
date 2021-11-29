#pragma once

#include <iostream>
#include <cstdlib>
#include "LinkStack.h"

// ��װ (
typedef struct MYCHAR {
	StackNode node;

	char* pAddr;  // ָ��ָ��ľ�����Ҫ��ջ���ĸ� (
	int   index;  // ��ʾ ( ���ַ����е�λ��(�±�)
}MyChar;

MyChar* CreateMyChar(char* p, int idx);

bool IsLeft(char c);

bool IsRight(char c);

// ���ַ��� str �� pos λ�õķ���ƥ��ʧ��
void ShowError(char* str, int pos);