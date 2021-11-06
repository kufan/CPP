#include <cstdlib>
#include "SeqQueue.h"

// 初始化队列
SeqQueue* Init_SeqQueue() {
	SeqQueue* queue = NULL;
	queue = (SeqQueue*)malloc(sizeof(SeqQueue));
	if (NULL == queue) {
		perror("malloc");
		return NULL;
	}

	// 初始化堆区空间
	for (int i = 0; i < MAX_SIZE; i++) {
		queue->Data[i] = NULL;
	}
	queue->size = 0;   // 起始时，队列中没有元素

	return queue;
}

// 入队操作: 就是在队尾，插入一个元素
// 其本质就是在数组尾部插入一个新的元素
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

	// 此时数组中有 size 个元素，那么最后一个元素下标: size-1
	// 新来一个元素，新元素的下标就会是 size
	queue->Data[queue->size] = dt;
	queue->size++;

	return 0;
}

// 出队操作：就是删除队首元素
// 其本质，就是删除数组中首元素
int Pop_SeqQueue(SeqQueue* queue) {
	if (NULL == queue) {
		return -1;
	}
	if (queue->size == 0) {
		return -2;
	}

	// 删除数组首元素
	for (int i = 0; i < queue->size - 1; i++) {
		queue->Data[i] = queue->Data[i + 1];
	}
	queue->size--;

	return 0;
}

// 获得队首元素: 其实就是数组中的首元素
void* Front_SeqQueue(SeqQueue* queue) {
	if (NULL == queue) {
		return NULL;
	}
	
	if (0 == queue->size) {
		return NULL;
	}

	return queue->Data[0];
}

// 获得队尾元素
void* Back_SeqQueue(SeqQueue* queue) {
	if (NULL == queue) {
		return NULL;
	}

	if (0 == queue->size) {
		return NULL;
	}

	return queue->Data[queue->size-1];
}

// 获得队列大小
int GetSize_SeqQueue(SeqQueue* queue) {
	if (NULL == queue) {
		return -1;
	}

	return queue->size;
}

// 清空队列
int Clear_SeqQueue(SeqQueue* queue) {
	if (NULL == queue) {
		return -1;
	}
	// 初始化堆区空间
	for (int i = 0; i < MAX_SIZE; i++) {
		queue->Data[i] = NULL;
	}
	queue->size = 0;   // 队列中元素被清空

	return 0;
}

// 销毁队列
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