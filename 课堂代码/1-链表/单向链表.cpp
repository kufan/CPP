#include <iostream>
#include <cstring>
// 由库提供的头文件，用 <> 包裹

#include "LinkList.h"
// 自定义头文件，用 双引号包裹

using namespace std;
// 在项目中，千万要谨慎，不要轻易打开 std 的名字空间


// 确定要保存到链表中的数据
typedef struct STUDENT {
	// 借助 node 维护数据域
	LinkNode node;  // 挂钩，也是 Linux 内核链表的核心要点
	
	char name[100];  // 当作字符串处理
	int age;
	char sex;
}Stu;


// 提供打印数据的回调函数
// typedef void(*PRINTNODE)(LinkNode*);
void MyPrint(LinkNode* dt) {
	Stu* s = (Stu*)dt;

	cout << "name: " << s->name << ", age: " << s->age << ", sex: " << s->sex << endl;
}

// 提供比较数据的回调函数
// typedef int(*COMPARENODE)(LinkNode*, LinkNode*);
int MyCompare(LinkNode* dt1, LinkNode* dt2) {
	Stu* s1 = (Stu*)dt1;
	Stu* s2 = (Stu*)dt2;

	if (strcmp(s1->name, s2->name)==0 && s1->age==s2->age && s1->sex==s2->sex) {
		return 0;
	}

	return -1;
}

int main()
{

	// 初始化链表
	LinkList* list = Init_LinkList();

	// 准备数据
	Stu s1 = {NULL, "aaa", 14, 'F'};
	Stu s2 = {NULL, "bbb", 15, 'M'};
	Stu s3 = {NULL, "ccc", 16, 'F'};
	Stu s4 = {NULL, "ddd", 17, 'M'};
	Stu s5 = {NULL, "eee", 18, 'F'};

	// int Insert_LinkList(LinkList* list, int pos, LinkNode* dt);
	Insert_LinkList(list, 0, (LinkNode*)&s1);
	Insert_LinkList(list, 1, (LinkNode*)&s2);
	Insert_LinkList(list, 2, (LinkNode*)&s3);
	Insert_LinkList(list, 3, (LinkNode*)&s4);
	Insert_LinkList(list, 4, (LinkNode*)&s5);

	// print 是一个函数指针类型的变量，用来保存一个函数的地址
	// int Print_LinkList(LinkList* list, PRINTNODE print);
	// cout << "MyPrint 函数的地址： " << MyPrint << endl;
	Print_LinkList(list, MyPrint);  // 把函数 MyPrint() 的地址传递
	// Print_LinkList(list, MyPrint()); // 函数的返回值，作为参数传递 


	// int Find_LinkList(LinkList* list, LinkNode* dt, COMPARENODE compare);
	Stu s6 = { NULL, "ddd", 17, 'M' };
	int res = Find_LinkList(list, (LinkNode*)&s6, MyCompare);
	if (res < 0) {
		cout << "链表中不存在该节点" << endl;
	} else {
		cout << "存在该节点,其第一次出现的位置： " << res << endl;
	}
	
	
	Destory_LinkList(list);
	
	return 0;
}