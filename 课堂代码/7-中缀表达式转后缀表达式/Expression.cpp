#include "Expression.h"

// ��װ��ջ����
MyChar* CreateMyChar(char* ptr) {
	MyChar* my = NULL;

	my = (MyChar*)malloc(sizeof(MyChar));
	if (my == NULL) {
		perror("malloc");
		return NULL;
	}

	my->p = ptr;

	return my;
}

// ʶ������
bool IsNumber(char c) {
	return c >= '0' && c <= '9';
}

// ʶ�� (
bool IsLeft(char c) {
	return '(' == c;
}

// ʶ�� )
bool IsRight(char c) {
	return ')' == c;
}

// ʶ�������
bool IsOperator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}

// ������ȼ�
int GetPriority(char c) {
	if (c == '+' || c == '-') {
		return 1;
	}
	if (c == '*' || c == '/') {
		return 2;
	}

	return 0;
}

// ���ֵĲ���
int NumberOperator(char* p) {
	if (NULL == p) {
		return -1;
	}
	
	printf("%c", *p);
	return 0;
}

// �����ŵĲ���: ֱ����ջ
int LeftOperator(LinkStack* stack, char* p) {
	if (NULL == stack) {
		return -1;
	}
	if (NULL == p) {
		return -2;
	}

	// char* �޷�ֱ����ջ
	MyChar* my = CreateMyChar(p);

	// int Push_LinkStack(LinkStack* stack, StackNode* dt);
	Push_LinkStack(stack, (StackNode*)my);

	return 0;
}

// �����ŵĲ���: ջ���������γ�ջ��ֱ������ '('ʱֹͣ
int RightOperator(LinkStack* stack) {
	if (NULL == stack) {
		return -1;
	}

	while (GetSize_LinkStack(stack) > 0) {
		// StackNode* Front_LinkStack(LinkStack* stack);
		MyChar* my = (MyChar*)Front_LinkStack(stack);

		// bool IsLeft(char c);
		if (IsLeft(*(my->p))) {
			Pop_LinkStack(stack);

			if (my != NULL) {
				free(my);
				my = NULL;
			}
			
			break;
		}

		// ��ӡջ��Ԫ��
		printf("%c", *(my->p));
		Pop_LinkStack(stack);
		if (my != NULL) {
			free(my);
			my = NULL;
		}
	}

	return 0;
}


// ������Ĳ���
/*
1����ɨ�赽�������(�����������)������ǰջ��Ԫ�������ȼ��Ƚ�
2�������ջ���������ȼ��ͣ������������ֱ����ջ
3�����ջ���������ȼ� ���� -->  >=
	ջ�����ų�ջ������ӡ��Ȼ��Ƚ���һ����ֱ��ջ���������ȵ�
		Ȼ������������ ��ջ
*/
// ָ�� p ��ָ������������Ҫ��ջ
int OperatorOperate(LinkStack* stack, char* p) {
	if (NULL == stack) {
		return -1;
	}
	if (NULL == p) {
		return -2;
	}

	// �Ƚ�ջ�����ź� p ָ����ĸ�����֮��ģ����ȼ�
	// StackNode* Front_LinkStack(LinkStack* stack);
	MyChar* top = (MyChar*)Front_LinkStack(stack);
	if (top == NULL) {
		// ��ǰջΪ�գ���ֱ����ջ
		MyChar* pp = CreateMyChar(p);
		Push_LinkStack(stack, (StackNode*)pp);
		return 0;  // return ��䣬�սắ��
	}
	

	// int GetPriority(char c);
	// 1��ջ��Ԫ�����ȼ� < p�����ȼ�
	if (GetPriority(*(top->p)) < GetPriority(*p)) {
		Push_LinkStack(stack, (StackNode*)CreateMyChar(p));
	} else {
		// 2��ջ��Ԫ�����ȼ� >= p�����ȼ�
		// ��ʱ��ջ��Ԫ��Ҫ��ջ
		while (GetSize_LinkStack(stack) > 0) {
			// ȡ��ջ��Ԫ��
			MyChar* my = (MyChar*)Front_LinkStack(stack);

			// �����ǰ��ջ������ < p�����ȼ�
			// ��ô p ��ջ
			if (GetPriority(*(my->p)) < GetPriority(*p)) {
				Push_LinkStack(stack, (StackNode*)CreateMyChar(p));
				return 0;
			}

			// ����ջ��Ԫ�س�ջ����ӡ���ж���һ���� p �Ĺ�ϵ
			printf("%c", *(my->p));
			Pop_LinkStack(stack);
			if (my != NULL) {
				free(my);
				my = NULL;
			}	
		}
	}

	return 0;
}