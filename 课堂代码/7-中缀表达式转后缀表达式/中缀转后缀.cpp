#include <iostream>

#include "LinkStack.h"
#include "Expression.h"

using namespace std;

/*
转换规则:
	1、把中缀表达式当作字符串，然后扫描
	2、如果是数字，则直接输出
	3、如果是 '('，则直接入栈
		'(' 的优先级最低
	4、如果是 ')'
		栈顶符号，依次出栈，直到遇到 '(' 停止出栈
		'(' 和 ')' 不会打印
		后缀表达式中，不会有任何符号
	5、如果是运算符,则用扫描到的符号，和当前栈顶符号做优先级的比较
		如果栈顶符号优先级低，则扫描到的符号 入栈
		如果栈顶符号优先级不低(>=)，则栈顶符号出栈
			直到栈顶符号优先级低，则扫描到符号入栈

案例中，只处理 + - * / 四则运算
*/


int main()
{
	char str[] = "8+(3-1)*5";  // 831-5*+
	char* p = str;

	LinkStack* stack = Init_Stack();

	while (*p != '\0') {
		// 如果是数字
		if (IsNumber(*p)) {
			NumberOperator(p);
		}
		
		// 如果是左括号
		if (IsLeft(*p)) {
			LeftOperator(stack, p);
		}

		// 如果是右括号
		if (IsRight(*p)) {
			RightOperator(stack);
		}

		// 如果是运算符
		if (IsOperator(*p)) {
			OperatorOperate(stack, p);
		}
		
		p++;
	}

	// 字符串扫描完毕，但是栈中还有元素，则依次出栈并打印
	while (GetSize_LinkStack(stack) > 0) {
		MyChar* my = (MyChar*)Front_LinkStack(stack);
		printf("%c", *(my->p));
		Pop_LinkStack(stack);

		if (my != NULL) {
			free(my);
			my = NULL;
		}
	}

	cout << endl;
	Destroy_LinkStack(stack);
	
	return 0;
}