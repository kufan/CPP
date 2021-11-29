#include <iostream>

#include "LinkStack.h"
#include "match.h"

using namespace std;

int main()
{
	LinkStack* stack = Init_Stack();

	char str[] = "1+2+6(dsf)df)sflp(sdfs)";

	char* p = str;
	int idx = 0;   // idx 下标，指向字符串中首元素
	int flag = 1;  // 起始时，假设一定可以匹配成功

	
	while (*p != '\0') {
		if (IsLeft(*p)) {
			// 入栈
			// 指针 p 所指向的，下标事 idx 的 (
			MyChar* my = CreateMyChar(p, idx);
			// int Push_LinkStack(LinkStack* stack, StackNode* dt);
			Push_LinkStack(stack, (StackNode*)my);
		}

		if (IsRight(*p)) {
			// 拿出栈顶元素，跟当前的 ) 匹配
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
				flag = 0;  // 假设失败，改变 flag 的值
				// 此时栈空
				cout << "右空号匹配失败: \n";
				ShowError(str, idx);
				break;
			}
		}


		p++;
		idx++;
	}


	while (GetSize_LinkStack(stack) > 0) {
		flag = 0;
		cout << "左括号匹配失败\n";

		MyChar* mychar = (MyChar*)Front_LinkStack(stack);
		ShowError(str, mychar->index);
		Pop_LinkStack(stack);
		break;
	}

	if (flag == 1) {
		cout << "匹配成功" << endl;
	}
	
	return 0;
}