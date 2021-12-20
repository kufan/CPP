#pragma once

#include <cstdio>
#include <cstdlib>

#include "LinkStack.h"


// ����ջ����������һ�� char ������ֱ����ջ
// ������Ҫ�Ӵ���ջ��������װ
typedef struct MYCHAR {
	StackNode node;
	char* p;  // ָ�� p ��ָ����ĸ����ţ�������Ҫ��ջ�ķ���
}MyChar;

// ��װ��ջ����
MyChar* CreateMyChar(char* ptr);

// ʶ������
bool IsNumber(char c);

// ʶ�� (
bool IsLeft(char c);

// ʶ�� )
bool IsRight(char c);

// ʶ�������
bool IsOperator(char c);

// ������ȼ�
int GetPriority(char c);

// ���ֵĲ���
int NumberOperator(char* p);

// �����ŵĲ���: ֱ����ջ
int LeftOperator(LinkStack* stack, char* p);

// �����ŵĲ���: ջ���������γ�ջ��ֱ������ '('ʱֹͣ
int RightOperator(LinkStack* stack);


// ������Ĳ���
/*
1����ɨ�赽�������(�����������)������ǰջ��Ԫ�������ȼ��Ƚ�
2�������ջ���������ȼ��ͣ������������ֱ����ջ
3�����ջ���������ȼ� ���� -->  >=
	ջ�����ų�ջ������ӡ��Ȼ��Ƚ���һ����ֱ��ջ���������ȵ�
		Ȼ������������ ��ջ
*/
// ָ�� p ��ָ������������Ҫ��ջ
int OperatorOperate(LinkStack* stack, char* p);