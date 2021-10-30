#include <cstdlib>
#include <cstring>
#include <cstdio>

#include "LinkList.h"

// 初始化链表
LinkList* Init_LinkList() {
	LinkList* list = NULL;

	// new
	list = (LinkList*)malloc(sizeof(LinkList));
	if (NULL == list) {
		// perror() 能捕获内核产生的错误(异常)
		perror("malloc: ");
		return NULL;
	}

	// 手动初始化堆区空间
	list->head.next = NULL;
	list->size      = 0;
	
	return list;
}

// 插入操作
// 给链表 list 的 pos 位置插入一个 dt 的节点
int Insert_LinkList(LinkList* list, int pos, LinkNode* dt) {
	// 参数合法性判断
	if (NULL == list) {
		return -1;
	}
	if (pos < 0 || pos > list->size) {
		return -2;
	}
	if (NULL == dt) {
		return -3;
	}

	// 确定插入点
	// 链表没有下标概念，从第一个节点开始往后数，数到第 pos 个节点即可
	LinkNode* pCur = &(list->head);
	for (int i = 0; i < pos; i++) {
		pCur = pCur->next;
	}
	// 指针 pCur 指向的是第 pos 个节点的前驱
	
	// 执行插入操作
	dt->next   = pCur->next;
	pCur->next = dt;
	

	// 更新 size 
	list->size++;
	
	return 0;
}

// 删除操作： 删除链表 list 中第 pos 个节点
int Delete_LinkList(LinkList* list, int pos) {
	if (NULL == list) {
		return -1;
	}
	if (pos < 0 || pos > list->size) {
		return -2;
	}

	// 确定第 pos 节点
	LinkNode* pCur = &(list->head);
	for (int i = 0; i < pos; i++) {
		pCur = pCur->next;
	}

	// 此时，pCur 指针，指向第 pos 个节点的前驱节点
	pCur->next = pCur->next->next;

	list->size--;

	return 0;
}

// 返回链表大小
int GetSize_LinkList(LinkList* list) {
	if (NULL == list) {
		return -1;
	}
	
	return list->size;
}


// 遍历链表
// 第二个参数，用来接受一个函数的地址
int Print_LinkList(LinkList* list, PRINTNODE print) {
	if (NULL == list) {
		return -1;
	}
	if (NULL == print) {
		return -2;
	}
	// printf("参数 print = %p\n", print);
	
	// 不遍历头节点--从第一个节点开始
	// 头节点中，不存储有效数据
	LinkNode* pCur = list->head.next;
	while (pCur != NULL) {
		// 调用 回调函数
		print(pCur);   // 根据函数的地址，调用函数
		pCur = pCur->next;
	}

	return 0;
}

// 查找操作
int Find_LinkList(LinkList* list, LinkNode* dt, COMPARENODE compare) {
	if (NULL == list) {
		return -1;
	}
	if (NULL == dt) {
		return -2;
	}
	if (NULL == compare) {

		return -3;
	}

	int idx = -4;
	LinkNode* pCur = list->head.next;
	for (int i = 0; i < list->size; i++) {
		if (compare(pCur, dt) == 0) {
			idx = i;
			break;
		}

		pCur = pCur->next;
	}

	return idx;
}

// 销毁链表
int Destory_LinkList(LinkList* list) {
	if (NULL == list) {
		return -1;
	}

	if (NULL != list) {
		free(list);
		list = NULL;
	}

	return 0;
}