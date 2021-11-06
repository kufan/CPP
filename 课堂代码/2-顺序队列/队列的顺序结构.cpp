#include <iostream>
#include <string>

#include "SeqQueue.h"

using namespace std;

/*

数组头，模拟队头
	从队头出队 -- 其实就是删除数组首元素
数组尾，模拟队尾
	从队尾入队 -- 其实就是删除数组尾元素
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

	// 入队
	// int Push_SeqQueue(SeqQueue* queue, void* dt);
	Push_SeqQueue(queue, &s1);
	Push_SeqQueue(queue, &s2);
	Push_SeqQueue(queue, &s3);
	Push_SeqQueue(queue, &s4);
	Push_SeqQueue(queue, &s5);

	// void* Front_SeqQueue(SeqQueue* queue);
	Stu* Head = (Stu*)Front_SeqQueue(queue);
	cout << "队头: name " << Head->name << ", age = " << Head->age << endl;


	Stu* Rear = (Stu*)Back_SeqQueue(queue);
	cout << "队尾: name " << Rear->name << ", age = " << Rear->age << endl;


	cout << "\n依次出队\n";
	while (queue->size != 0) {
		// 只能从对头出队
		Stu* h = (Stu*)Front_SeqQueue(queue);
		cout << "当前队头: name " << h->name << ", age = " << h->age << endl;

		Pop_SeqQueue(queue);
	}
	
	Desatory_SeqQueue(queue);
	
	return 0;
}