#include <iostream>

#include "LinkStack.h"
#include "match.h"

using namespace std;

int main()
{
	LinkStack* stack = Init_Stack();

	char str[] = "1+2+6(dsf)df)sflp(sdfs)";

	char* p = str;
	int idx = 0;   // idx �±ָ꣬���ַ�������Ԫ��
	int flag = 1;  // ��ʼʱ������һ������ƥ��ɹ�

	
	while (*p != '\0') {
		if (IsLeft(*p)) {
			// ��ջ
			// ָ�� p ��ָ��ģ��±��� idx �� (
			MyChar* my = CreateMyChar(p, idx);
			// int Push_LinkStack(LinkStack* stack, StackNode* dt);
			Push_LinkStack(stack, (StackNode*)my);
		}

		if (IsRight(*p)) {
			// �ó�ջ��Ԫ�أ�����ǰ�� ) ƥ��
			if (GetSize_LinkStack(stack) > 0) {
				MyChar* mychar = (MyChar*)Front_LinkStack(stack);
				if (IsLeft(*(mychar->pAddr))) {
					Pop_LinkStack(stack);

					if (mychar != NULL) {
						free(mychar);
						mychar = NULL;
					}
				}
				
			} else {
				flag = 0;  // ����ʧ�ܣ��ı� flag ��ֵ
				// ��ʱջ��
				cout << "�ҿպ�ƥ��ʧ��: \n";
				ShowError(str, idx);
				break;
			}
		}


		p++;
		idx++;
	}


	while (GetSize_LinkStack(stack) > 0) {
		flag = 0;
		cout << "������ƥ��ʧ��\n";

		MyChar* mychar = (MyChar*)Front_LinkStack(stack);
		ShowError(str, mychar->index);
		Pop_LinkStack(stack);
		break;
	}

	if (flag == 1) {
		cout << "ƥ��ɹ�" << endl;
	}
	
	return 0;
}