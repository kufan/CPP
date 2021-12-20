#pragma once

#include <cstdio>
#include <cstdlib>

#include "LinkStack.h"


// 有入栈操作，但是一个 char 不可能直接入栈
// 所以需要队待入栈符号做封装
typedef struct MYCHAR {
	StackNode node;
	char* p;  // 指针 p 所指向的哪个符号，就是需要入栈的符号
}MyChar;

// 封装入栈符号
MyChar* CreateMyChar(char* ptr);

// 识别数字
bool IsNumber(char c);

// 识别 (
bool IsLeft(char c);

// 识别 )
bool IsRight(char c);

// 识别运算符
bool IsOperator(char c);

// 获得优先级
int GetPriority(char c);

// 数字的操作
int NumberOperator(char* p);

// 左括号的操作: 直接入栈
int LeftOperator(LinkStack* stack, char* p);

// 右括号的操作: 栈顶符号依次出栈，直到遇到 '('时停止
int RightOperator(LinkStack* stack);


// 运算符的操作
/*
1、用扫描到的运算符(待操作运算符)，跟当前栈顶元素做优先级比较
2、如果，栈顶符号优先级低，待操作运算符直接入栈
3、如果栈顶符号优先级 不低 -->  >=
	栈顶符号出栈，并打印，然后比较下一个，直到栈顶符号优先低
		然后待操作运算符 入栈
*/
// 指针 p 所指向的运算符，需要入栈
int OperatorOperate(LinkStack* stack, char* p);