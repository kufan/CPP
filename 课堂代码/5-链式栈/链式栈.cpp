#include <iostream>
#include <string>

#include "LinkStack.h"

using namespace std;

// ������� ͷ�� ģ��ջ��


typedef struct STUDENT {
	StackNode node;

	string name;
	int age;
}Stu;

int main()
{

	LinkStack* stack = Init_Stack();

	// ��������
	Stu s1 = {{NULL}, "aaa", 13};
	Stu s2 = {{NULL}, "bbb", 14};
	Stu s3 = {{NULL}, "ccc", 15};
	Stu s4 = {{NULL}, "ddd", 16};
	Stu s5 = {{NULL}, "eee", 17};

	// int Push_LinkStack(LinkStack* stack, StackNode* dt);
	Push_LinkStack(stack, (StackNode* )&s1);  // ������ջ����ջ��
	Push_LinkStack(stack, (StackNode* )&s2);
	Push_LinkStack(stack, (StackNode* )&s3);
	Push_LinkStack(stack, (StackNode* )&s4);
	Push_LinkStack(stack, (StackNode* )&s5); // �����ջ����ջ��


	Stu* head = (Stu*)Front_LinkStack(stack);
	cout << "ջ��Ԫ�أ� name : " << head->name << ", age = " << head->age << endl;

	cout << "\n���γ�ջ:\n";
	while (GetSize_LinkStack(stack) > 0) {
		Stu* h = (Stu*)Front_LinkStack(stack);
		cout << "��ǰջ��Ԫ�أ� name : " << h->name << ", age = " << h->age << endl;

		Pop_LinkStack(stack);
		
	}
	
	if (IsEmpty_LinkStack(stack)) {
		cout << "ջ��" << endl;
	} else {
		cout << "��Ϊ��" << endl;
	}

	Destroy_LinkStack(stack);
	

	return 0;
}