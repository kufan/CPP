#pragma once

#include "LinkStack.h"

// 数字需要入栈，但是数字不能直接入栈，所以队数字进行封装
typedef struct MYNUM {
    StackNode node;
    int val;  // 真正需要入栈的数字
}MyNum;

bool IsNumber(char c);

int Caculate(int left, int right, char c);