#include <cstdlib>

#include "LinkStack.h"

// ��ʼ��ջ
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

// ��ջ
int Push_LinkStack(LinkStack* stack, StackNode* dt) {
	if (NULL == stack) {
		return -1;
	}
	if (NULL == dt) {
		return -2;
	}

	// ������ͷ�������µ�Ԫ��
	dt->next = stack->head.next;
	stack->head.next = dt;

	stack->size++;

	return 0;
}


// ����ջ��Ԫ��
StackNode* Front_LinkStack(LinkStack* stack) {
	if (NULL == stack) {
		return NULL;
	}
	if (0 == stack->size) {
		return NULL;
	}

	return stack->head.next;
}

// ��ջ����
int Pop_LinkStack(LinkStack* stack) {
	if (NULL == stack) {
		return -1;
	}
	if (NULL == stack->size) {
		return -2;
	}

	// ɾ�������е�һ���ڵ�
	StackNode* pDel = stack->head.next;
	stack->head.next = pDel->next;
	
	stack->size--;

	return 0;
}

// ����ջ��Ԫ�ظ���
int GetSize_LinkStack(LinkStack* stack) {
	if (stack == NULL) {
		return -1;
	}

	return stack->size;
}

// �ж�ջ�Ƿ�Ϊ��
int IsEmpty_LinkStack(LinkStack* stack) {
	if (stack == NULL) {
		return -1;
	}

	if (0 == stack->size) {
		return LINKSTACK_TRUE;
	}

	return LINKSTACK_FALSE;
	
}

// ���
int Clear_LinkStack(LinkStack* stack) {
	if (stack == NULL) {
		return -1;
	}
	
	stack->head.next = NULL;
	stack->size = 0;

	return 0;
}

// ����
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