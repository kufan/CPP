#pragma once

#define MAX_SIZE  1024
// �򵥺꣬����һ�ּ򵥵��滻��ϵ

// ����ģ�����
typedef struct SEQEUEUE {
	// ָ�����飺������ֻ�ܱ���ָ�룬�����п��Ա����������͵�����
	void* Data[MAX_SIZE];
	int size;  // ��ʾ������Ԫ�ظ�������ʵ���Ƕ�����Ԫ�ظ���
}SeqQueue;

// ��ʼ������
SeqQueue* Init_SeqQueue();

// ��Ӳ���: �����ڶ�β������һ��Ԫ��
// �䱾�ʾ���������β������һ���µ�Ԫ��
int Push_SeqQueue(SeqQueue* queue, void* dt);

// ���Ӳ���������ɾ������Ԫ��
// �䱾�ʣ�����ɾ����������Ԫ��
int Pop_SeqQueue(SeqQueue* queue);

// ��ö���Ԫ��
void* Front_SeqQueue(SeqQueue* queue);

// ��ö�βԪ��
void* Back_SeqQueue(SeqQueue* queue);

// ��ö��д�С
int GetSize_SeqQueue(SeqQueue* queue);

// ��ն���
int Clear_SeqQueue(SeqQueue* queue);

// ���ٶ���
int Desatory_SeqQueue(SeqQueue* queue);