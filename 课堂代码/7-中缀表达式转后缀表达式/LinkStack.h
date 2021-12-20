#pragma once  

#define LINKSTACK_TRUE  1
#define LINKSTACK_FALSE 0

// 设计链表节点
typedef struct STACKNODE {
	// 数据域交给用户去维护
	struct STACKNODE* next;  // 只有指针域,用来指向下一个节点
}StackNode;

// 设计链表的起点
typedef struct LINKSTACK {
	StackNode head;  // 头节点
	int size;   // 表示链表中节点个数(起始就是栈中元素个数)
}LinkStack;

// 初始化栈
LinkStack* Init_Stack();

// 入栈
int Push_LinkStack(LinkStack* stack, StackNode* dt);

// 返回栈顶元素
StackNode* Front_LinkStack(LinkStack* stack);

// 出栈操作
int Pop_LinkStack(LinkStack* stack);

// 返回栈中元素个数
int GetSize_LinkStack(LinkStack* stack);

// 判断栈是否为空
int IsEmpty_LinkStack(LinkStack* stack);

// 清空
int Clear_LinkStack(LinkStack* stack);

// 销毁
int Destroy_LinkStack(LinkStack* stack);