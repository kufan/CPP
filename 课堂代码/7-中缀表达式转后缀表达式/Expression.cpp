#include "Expression.h"

// 封装入栈符号
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

// 识别数组
bool IsNumber(char c) {
	return c >= '0' && c <= '9';
}

// 识别 (
bool IsLeft(char c) {
	return '(' == c;
}

// 识别 )
bool IsRight(char c) {
	return ')' == c;
}

// 识别运算符
bool IsOperator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}

// 获得优先级
int GetPriority(char c) {
	if (c == '+' || c == '-') {
		return 1;
	}
	if (c == '*' || c == '/') {
		return 2;
	}

	return 0;
}

// 数字的操作
int NumberOperator(char* p) {
	if (NULL == p) {
		return -1;
	}
	
	printf("%c", *p);
	return 0;
}

// 左括号的操作: 直接入栈
int LeftOperator(LinkStack* stack, char* p) {
	if (NULL == stack) {
		return -1;
	}
	if (NULL == p) {
		return -2;
	}

	// char* 无法直接入栈
	MyChar* my = CreateMyChar(p);

	// int Push_LinkStack(LinkStack* stack, StackNode* dt);
	Push_LinkStack(stack, (StackNode*)my);

	return 0;
}

// 右括号的操作: 栈顶符号依次出栈，直到遇到 '('时停止
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

		// 打印栈顶元素
		printf("%c", *(my->p));
		Pop_LinkStack(stack);
		if (my != NULL) {
			free(my);
			my = NULL;
		}
	}

	return 0;
}


// 运算符的操作
/*
1、用扫描到的运算符(待操作运算符)，跟当前栈顶元素做优先级比较
2、如果，栈顶符号优先级低，待操作运算符直接入栈
3、如果栈顶符号优先级 不低 -->  >=
	栈顶符号出栈，并打印，然后比较下一个，直到栈顶符号优先低
		然后待操作运算符 入栈
*/
// 指针 p 所指向的运算符，需要入栈
int OperatorOperate(LinkStack* stack, char* p) {
	if (NULL == stack) {
		return -1;
	}
	if (NULL == p) {
		return -2;
	}

	// 比较栈顶符号和 p 指向的哪个符号之间的，优先级
	// StackNode* Front_LinkStack(LinkStack* stack);
	MyChar* top = (MyChar*)Front_LinkStack(stack);
	if (top == NULL) {
		// 当前栈为空，则直接入栈
		MyChar* pp = CreateMyChar(p);
		Push_LinkStack(stack, (StackNode*)pp);
		return 0;  // return 语句，终结函数
	}
	

	// int GetPriority(char c);
	// 1、栈顶元素优先级 < p的优先级
	if (GetPriority(*(top->p)) < GetPriority(*p)) {
		Push_LinkStack(stack, (StackNode*)CreateMyChar(p));
	} else {
		// 2、栈顶元素优先级 >= p的优先级
		// 此时，栈顶元素要出栈
		while (GetSize_LinkStack(stack) > 0) {
			// 取得栈顶元素
			MyChar* my = (MyChar*)Front_LinkStack(stack);

			// 如果当前的栈顶优先 < p的优先级
			// 那么 p 入栈
			if (GetPriority(*(my->p)) < GetPriority(*p)) {
				Push_LinkStack(stack, (StackNode*)CreateMyChar(p));
				return 0;
			}

			// 否则，栈顶元素出栈，打印，判断下一个和 p 的关系
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