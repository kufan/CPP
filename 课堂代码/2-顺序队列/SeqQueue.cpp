#include <cstdlib>
#include "SeqQueue.h"

// ��ʼ������
SeqQueue* Init_SeqQueue() {
	SeqQueue* queue = NULL;
	queue = (SeqQueue*)malloc(sizeof(SeqQueue));
	if (NULL == queue) {
		perror("malloc");
		return NULL;
	}

	// ��ʼ�������ռ�
	for (int i = 0; i < MAX_SIZE; i++) {
		queue->Data[i] = NULL;
	}
	queue->size = 0;   // ��ʼʱ��������û��Ԫ��

	return queue;
}

// ��Ӳ���: �����ڶ�β������һ��Ԫ��
// �䱾�ʾ���������β������һ���µ�Ԫ��
int Push_SeqQueue(SeqQueue* queue, void* dt) {
	if (NULL == queue) {
		return -1;
	}
	if (NULL == dt) {
		return -2;
	}
	if (queue->size == MAX_SIZE) {
		return -3;
	}

	// ��ʱ�������� size ��Ԫ�أ���ô���һ��Ԫ���±�: size-1
	// ����һ��Ԫ�أ���Ԫ�ص��±�ͻ��� size
	queue->Data[queue->size] = dt;
	queue->size++;

	return 0;
}

// ���Ӳ���������ɾ������Ԫ��
// �䱾�ʣ�����ɾ����������Ԫ��
int Pop_SeqQueue(SeqQueue* queue) {
	if (NULL == queue) {
		return -1;
	}
	if (queue->size == 0) {
		return -2;
	}

	// ɾ��������Ԫ��
	for (int i = 0; i < queue->size - 1; i++) {
		queue->Data[i] = queue->Data[i + 1];
	}
	queue->size--;

	return 0;
}

// ��ö���Ԫ��: ��ʵ���������е���Ԫ��
void* Front_SeqQueue(SeqQueue* queue) {
	if (NULL == queue) {
		return NULL;
	}
	
	if (0 == queue->size) {
		return NULL;
	}

	return queue->Data[0];
}

// ��ö�βԪ��
void* Back_SeqQueue(SeqQueue* queue) {
	if (NULL == queue) {
		return NULL;
	}

	if (0 == queue->size) {
		return NULL;
	}

	return queue->Data[queue->size-1];
}

// ��ö��д�С
int GetSize_SeqQueue(SeqQueue* queue) {
	if (NULL == queue) {
		return -1;
	}

	return queue->size;
}

// ��ն���
int Clear_SeqQueue(SeqQueue* queue) {
	if (NULL == queue) {
		return -1;
	}
	// ��ʼ�������ռ�
	for (int i = 0; i < MAX_SIZE; i++) {
		queue->Data[i] = NULL;
	}
	queue->size = 0;   // ������Ԫ�ر����

	return 0;
}

// ���ٶ���
int Desatory_SeqQueue(SeqQueue* queue) {
	if (NULL == queue) {
		return -1;
	}

	if (queue != NULL) {
		free(queue);
		queue = NULL;
	}

	return 0;
}