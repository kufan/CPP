#pragma once

#include <iostream>
#include <cstdlib>
#include "LinkStack.h"

// 封装 (
typedef struct MYCHAR {
	StackNode node;

	char* pAddr;  // 指针指向的就是需要入栈的哪个 (
	int   index;  // 表示 ( 在字符串中的位置(下标)
}MyChar;

MyChar* CreateMyChar(char* p, int idx);

bool IsLeft(char c);

bool IsRight(char c);

// 在字符串 str 的 pos 位置的符号匹配失败
void ShowError(char* str, int pos);