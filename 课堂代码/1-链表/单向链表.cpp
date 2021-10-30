#include <iostream>
#include <cstring>
// �ɿ��ṩ��ͷ�ļ����� <> ����

#include "LinkList.h"
// �Զ���ͷ�ļ����� ˫���Ű���

using namespace std;
// ����Ŀ�У�ǧ��Ҫ��������Ҫ���״� std �����ֿռ�


// ȷ��Ҫ���浽�����е�����
typedef struct STUDENT {
	// ���� node ά��������
	LinkNode node;  // �ҹ���Ҳ�� Linux �ں�����ĺ���Ҫ��
	
	char name[100];  // �����ַ�������
	int age;
	char sex;
}Stu;


// �ṩ��ӡ���ݵĻص�����
// typedef void(*PRINTNODE)(LinkNode*);
void MyPrint(LinkNode* dt) {
	Stu* s = (Stu*)dt;

	cout << "name: " << s->name << ", age: " << s->age << ", sex: " << s->sex << endl;
}

// �ṩ�Ƚ����ݵĻص�����
// typedef int(*COMPARENODE)(LinkNode*, LinkNode*);
int MyCompare(LinkNode* dt1, LinkNode* dt2) {
	Stu* s1 = (Stu*)dt1;
	Stu* s2 = (Stu*)dt2;

	if (strcmp(s1->name, s2->name)==0 && s1->age==s2->age && s1->sex==s2->sex) {
		return 0;
	}

	return -1;
}

int main()
{

	// ��ʼ������
	LinkList* list = Init_LinkList();

	// ׼������
	Stu s1 = {NULL, "aaa", 14, 'F'};
	Stu s2 = {NULL, "bbb", 15, 'M'};
	Stu s3 = {NULL, "ccc", 16, 'F'};
	Stu s4 = {NULL, "ddd", 17, 'M'};
	Stu s5 = {NULL, "eee", 18, 'F'};

	// int Insert_LinkList(LinkList* list, int pos, LinkNode* dt);
	Insert_LinkList(list, 0, (LinkNode*)&s1);
	Insert_LinkList(list, 1, (LinkNode*)&s2);
	Insert_LinkList(list, 2, (LinkNode*)&s3);
	Insert_LinkList(list, 3, (LinkNode*)&s4);
	Insert_LinkList(list, 4, (LinkNode*)&s5);

	// print ��һ������ָ�����͵ı�������������һ�������ĵ�ַ
	// int Print_LinkList(LinkList* list, PRINTNODE print);
	// cout << "MyPrint �����ĵ�ַ�� " << MyPrint << endl;
	Print_LinkList(list, MyPrint);  // �Ѻ��� MyPrint() �ĵ�ַ����
	// Print_LinkList(list, MyPrint()); // �����ķ���ֵ����Ϊ�������� 


	// int Find_LinkList(LinkList* list, LinkNode* dt, COMPARENODE compare);
	Stu s6 = { NULL, "ddd", 17, 'M' };
	int res = Find_LinkList(list, (LinkNode*)&s6, MyCompare);
	if (res < 0) {
		cout << "�����в����ڸýڵ�" << endl;
	} else {
		cout << "���ڸýڵ�,���һ�γ��ֵ�λ�ã� " << res << endl;
	}
	
	
	Destory_LinkList(list);
	
	return 0;
}