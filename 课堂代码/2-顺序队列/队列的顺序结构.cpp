#include <iostream>
#include <string>

#include "SeqQueue.h"

using namespace std;

/*

����ͷ��ģ���ͷ
	�Ӷ�ͷ���� -- ��ʵ����ɾ��������Ԫ��
����β��ģ���β
	�Ӷ�β��� -- ��ʵ����ɾ������βԪ��
*/

typedef struct STUDENT {
	string name;
	int age;
}Stu;

int main()
{
	SeqQueue* queue = Init_SeqQueue();

	Stu s1 = { "aaa", 12 };
	Stu s2 = { "bbb", 13 };
	Stu s3 = { "ccc", 14 };
	Stu s4 = {"ddd", 15};
	Stu s5 = {"eee", 16};

	// ���
	// int Push_SeqQueue(SeqQueue* queue, void* dt);
	Push_SeqQueue(queue, &s1);
	Push_SeqQueue(queue, &s2);
	Push_SeqQueue(queue, &s3);
	Push_SeqQueue(queue, &s4);
	Push_SeqQueue(queue, &s5);

	// void* Front_SeqQueue(SeqQueue* queue);
	Stu* Head = (Stu*)Front_SeqQueue(queue);
	cout << "��ͷ: name " << Head->name << ", age = " << Head->age << endl;


	Stu* Rear = (Stu*)Back_SeqQueue(queue);
	cout << "��β: name " << Rear->name << ", age = " << Rear->age << endl;


	cout << "\n���γ���\n";
	while (queue->size != 0) {
		// ֻ�ܴӶ�ͷ����
		Stu* h = (Stu*)Front_SeqQueue(queue);
		cout << "��ǰ��ͷ: name " << h->name << ", age = " << h->age << endl;

		Pop_SeqQueue(queue);
	}
	
	Desatory_SeqQueue(queue);
	
	return 0;
}