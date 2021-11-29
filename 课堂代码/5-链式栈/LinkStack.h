#pragma once  

#define LINKSTACK_TRUE  1
#define LINKSTACK_FALSE 0

// �������ڵ�
typedef struct STACKNODE {
	// �����򽻸��û�ȥά��
	struct STACKNODE* next;  // ֻ��ָ����,����ָ����һ���ڵ�
}StackNode;

// �����������
typedef struct LINKSTACK {
	StackNode head;  // ͷ�ڵ�
	int size;   // ��ʾ�����нڵ����(��ʼ����ջ��Ԫ�ظ���)
}LinkStack;

// ��ʼ��ջ
LinkStack* Init_Stack();

// ��ջ
int Push_LinkStack(LinkStack* stack, StackNode* dt);

// ����ջ��Ԫ��
StackNode* Front_LinkStack(LinkStack* stack);

// ��ջ����
int Pop_LinkStack(LinkStack* stack);

// ����ջ��Ԫ�ظ���
int GetSize_LinkStack(LinkStack* stack);

// �ж�ջ�Ƿ�Ϊ��
int IsEmpty_LinkStack(LinkStack* stack);

// ���
int Clear_LinkStack(LinkStack* stack);

// ����
int Destroy_LinkStack(LinkStack* stack);