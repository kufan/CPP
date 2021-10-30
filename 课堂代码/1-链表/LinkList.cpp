#include <cstdlib>
#include <cstring>
#include <cstdio>

#include "LinkList.h"

// ��ʼ������
LinkList* Init_LinkList() {
	LinkList* list = NULL;

	// new
	list = (LinkList*)malloc(sizeof(LinkList));
	if (NULL == list) {
		// perror() �ܲ����ں˲����Ĵ���(�쳣)
		perror("malloc: ");
		return NULL;
	}

	// �ֶ���ʼ�������ռ�
	list->head.next = NULL;
	list->size      = 0;
	
	return list;
}

// �������
// ������ list �� pos λ�ò���һ�� dt �Ľڵ�
int Insert_LinkList(LinkList* list, int pos, LinkNode* dt) {
	// �����Ϸ����ж�
	if (NULL == list) {
		return -1;
	}
	if (pos < 0 || pos > list->size) {
		return -2;
	}
	if (NULL == dt) {
		return -3;
	}

	// ȷ�������
	// ����û���±����ӵ�һ���ڵ㿪ʼ�������������� pos ���ڵ㼴��
	LinkNode* pCur = &(list->head);
	for (int i = 0; i < pos; i++) {
		pCur = pCur->next;
	}
	// ָ�� pCur ָ����ǵ� pos ���ڵ��ǰ��
	
	// ִ�в������
	dt->next   = pCur->next;
	pCur->next = dt;
	

	// ���� size 
	list->size++;
	
	return 0;
}

// ɾ�������� ɾ������ list �е� pos ���ڵ�
int Delete_LinkList(LinkList* list, int pos) {
	if (NULL == list) {
		return -1;
	}
	if (pos < 0 || pos > list->size) {
		return -2;
	}

	// ȷ���� pos �ڵ�
	LinkNode* pCur = &(list->head);
	for (int i = 0; i < pos; i++) {
		pCur = pCur->next;
	}

	// ��ʱ��pCur ָ�룬ָ��� pos ���ڵ��ǰ���ڵ�
	pCur->next = pCur->next->next;

	list->size--;

	return 0;
}

// ���������С
int GetSize_LinkList(LinkList* list) {
	if (NULL == list) {
		return -1;
	}
	
	return list->size;
}


// ��������
// �ڶ�����������������һ�������ĵ�ַ
int Print_LinkList(LinkList* list, PRINTNODE print) {
	if (NULL == list) {
		return -1;
	}
	if (NULL == print) {
		return -2;
	}
	// printf("���� print = %p\n", print);
	
	// ������ͷ�ڵ�--�ӵ�һ���ڵ㿪ʼ
	// ͷ�ڵ��У����洢��Ч����
	LinkNode* pCur = list->head.next;
	while (pCur != NULL) {
		// ���� �ص�����
		print(pCur);   // ���ݺ����ĵ�ַ�����ú���
		pCur = pCur->next;
	}

	return 0;
}

// ���Ҳ���
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

// ��������
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