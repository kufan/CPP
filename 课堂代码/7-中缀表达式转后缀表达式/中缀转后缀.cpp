#include <iostream>

#include "LinkStack.h"
#include "Expression.h"

using namespace std;

/*
ת������:
	1������׺���ʽ�����ַ�����Ȼ��ɨ��
	2����������֣���ֱ�����
	3������� '('����ֱ����ջ
		'(' �����ȼ����
	4������� ')'
		ջ�����ţ����γ�ջ��ֱ������ '(' ֹͣ��ջ
		'(' �� ')' �����ӡ
		��׺���ʽ�У��������κη���
	5������������,����ɨ�赽�ķ��ţ��͵�ǰջ�����������ȼ��ıȽ�
		���ջ���������ȼ��ͣ���ɨ�赽�ķ��� ��ջ
		���ջ���������ȼ�����(>=)����ջ�����ų�ջ
			ֱ��ջ���������ȼ��ͣ���ɨ�赽������ջ

�����У�ֻ���� + - * / ��������
*/


int main()
{
	char str[] = "8+(3-1)*5";  // 831-5*+
	char* p = str;

	LinkStack* stack = Init_Stack();

	while (*p != '\0') {
		// ���������
		if (IsNumber(*p)) {
			NumberOperator(p);
		}
		
		// �����������
		if (IsLeft(*p)) {
			LeftOperator(stack, p);
		}

		// �����������
		if (IsRight(*p)) {
			RightOperator(stack);
		}

		// ����������
		if (IsOperator(*p)) {
			OperatorOperate(stack, p);
		}
		
		p++;
	}

	// �ַ���ɨ����ϣ�����ջ�л���Ԫ�أ������γ�ջ����ӡ
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