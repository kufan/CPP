#pragma once

#define MAX_SIZE  1024
// 简单宏，定义一种简单的替换关系

// 数组模拟队列
typedef struct SEQEUEUE {
	// 指针数组：数组中只能保存指针，队列中可以保存任意类型的数据
	void* Data[MAX_SIZE];
	int size;  // 表示数组中元素个数，其实就是队列中元素个数
}SeqQueue;

// 初始化队列
SeqQueue* Init_SeqQueue();

// 入队操作: 就是在队尾，插入一个元素
// 其本质就是在数组尾部插入一个新的元素
int Push_SeqQueue(SeqQueue* queue, void* dt);

// 出队操作：就是删除队首元素
// 其本质，就是删除数组中首元素
int Pop_SeqQueue(SeqQueue* queue);

// 获得队首元素
void* Front_SeqQueue(SeqQueue* queue);

// 获得队尾元素
void* Back_SeqQueue(SeqQueue* queue);

// 获得队列大小
int GetSize_SeqQueue(SeqQueue* queue);

// 清空队列
int Clear_SeqQueue(SeqQueue* queue);

// 销毁队列
int Desatory_SeqQueue(SeqQueue* queue);