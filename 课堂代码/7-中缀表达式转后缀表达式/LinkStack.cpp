#include <cstdlib>

#include "LinkStack.h"

// 初始化栈
LinkStack* Init_Stack() {
	LinkStack* stack = NULL;
	stack = (LinkStack*)malloc(sizeof(LinkStack));
	if (stack == NULL) {
		perror("malloc");
		return NULL;
	}

	stack->head.next = NULL;
	stack->size = 0;

	return stack;
}

// 入栈
int Push_LinkStack(LinkStack* stack, StackNode* dt) {
	if (NULL == stack) {
		return -1;
	}
	if (NULL == dt) {
		return -2;
	}

	// 在链表头部插入新的元素
	dt->next = stack->head.next;
	stack->head.next = dt;

	stack->size++;

	return 0;
}


// 返回栈顶元素
StackNode* Front_LinkStack(LinkStack* stack) {
	if (NULL == stack) {
		return NULL;
	}
	if (0 == stack->size) {
		return NULL;
	}

	return stack->head.next;
}

// 出栈操作
int Pop_LinkStack(LinkStack* stack) {
	if (NULL == stack) {
		return -1;
	}
	if (NULL == stack->size) {
		return -2;
	}

	// 删除链表中第一个节点
	StackNode* pDel = stack->head.next;
	stack->head.next = pDel->next;
	
	stack->size--;

	return 0;
}

// 返回栈中元素个数
int GetSize_LinkStack(LinkStack* stack) {
	if (stack == NULL) {
		return -1;
	}

	return stack->size;
}

// 判断栈是否为空
int IsEmpty_LinkStack(LinkStack* stack) {
	if (stack == NULL) {
		return -1;
	}

	if (0 == stack->size) {
		return LINKSTACK_TRUE;
	}

	return LINKSTACK_FALSE;
	
}

// 清空
int Clear_LinkStack(LinkStack* stack) {
	if (stack == NULL) {
		return -1;
	}
	
	stack->head.next = NULL;
	stack->size = 0;

	return 0;
}

// 销毁
int Destroy_LinkStack(LinkStack* stack) {
	if (stack == NULL) {
		return -1;
	}

	if (stack != NULL) {
		free(stack);
		stack = NULL;
	}

	return 0;
}