#include <iostream>
#include <string>

#include "LinkStack.h"

using namespace std;

// 用链表的 头部 模拟栈顶


typedef struct STUDENT {
	StackNode node;

	string name;
	int age;
}Stu;

int main()
{

	LinkStack* stack = Init_Stack();

	// 创建数据
	Stu s1 = {{NULL}, "aaa", 13};
	Stu s2 = {{NULL}, "bbb", 14};
	Stu s3 = {{NULL}, "ccc", 15};
	Stu s4 = {{NULL}, "ddd", 16};
	Stu s5 = {{NULL}, "eee", 17};

	// int Push_LinkStack(LinkStack* stack, StackNode* dt);
	Push_LinkStack(stack, (StackNode* )&s1);  // 最先入栈，在栈底
	Push_LinkStack(stack, (StackNode* )&s2);
	Push_LinkStack(stack, (StackNode* )&s3);
	Push_LinkStack(stack, (StackNode* )&s4);
	Push_LinkStack(stack, (StackNode* )&s5); // 最后入栈，在栈顶


	Stu* head = (Stu*)Front_LinkStack(stack);
	cout << "栈顶元素： name : " << head->name << ", age = " << head->age << endl;

	cout << "\n依次出栈:\n";
	while (GetSize_LinkStack(stack) > 0) {
		Stu* h = (Stu*)Front_LinkStack(stack);
		cout << "当前栈顶元素： name : " << h->name << ", age = " << h->age << endl;

		Pop_LinkStack(stack);
		
	}
	
	if (IsEmpty_LinkStack(stack)) {
		cout << "栈空" << endl;
	} else {
		cout << "不为空" << endl;
	}

	Destroy_LinkStack(stack);
	

	return 0;
}