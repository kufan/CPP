#pragma once
// ��ֹͷ�ļ����ظ����� -- �ڹ������쳣��Ҫ

// ��ƽڵ�
// �����򣬽����û�ȥά��!!!
typedef struct LINKNODE {
	struct LINKNODE* next;   // ָ��������������һ���ڵ�ĵ�ַ
}LinkNode;
// �ڵ�һ����ƺã����������ݵĸ�ʽҲ��ȷ����


// ���һ����������
// ��ʵ���Ƕ�ͷ�ڵ�ķ�װ -- �����ģ�Ϊ�˷����������
typedef struct LINKLIST {
	LinkNode head;   // ͷ�ڵ�
	int size;   // ��¼�����нڵ����
}LinkList;


// typedef: 1����ָ�����������; 2����������(typedef ����ģ�����������)
// ������� ����ָ������ �ķ�ʽ��ָ����ӡ�����ĸ�ʽ
typedef void(*PRINTNODE)(LinkNode*);
// void(*PRINTNODE)(LinkNode*) �������ͣ�����ָ������
// void(*PRINTNODE)(LinkNode*) a; ������һ������ a �� void(*PRINTNODE)(LinkNode*) ���͵ı���
// ��ʱ a ��������ָ�룬�� a ֻ��ָ��һ������(a ��ֻ�ܱ���һ�������ĵ�ַ)
// a ֻ��ָ�� û�з���ֵ����ֻ����һ�� LinkNode* ���Ͳ����� ����
// void(*PRINTNODE)(LinkNode*) ���Լ�дΪ PRINTNODE
// PRINTNODE a;



typedef int(*COMPARENODE)(LinkNode*, LinkNode*);
// int(*COMPARENODE)(LinkNode*, LinkNode*) ��������
// int(*COMPARENODE)(LinkNode*, LinkNode*) a;
// a ֻ��ָ��һ���� int ����ֵ���������� LinkNode* ���͵Ĳ�����  ����
// int(*COMPARENODE)(LinkNode*, LinkNode*) ���Լ�дΪ COMPARENODE


// ��ʼ������ -- ����һ������
// ��ʵ���ǰ�����ʼ������
// �����߿������ݵ���������
// �����ڶ�������ʼ��������ʼ���ɹ��󷵻ظ�����ĵ�ַ
LinkList* Init_LinkList();
// ָ�뺯�� -- һ������ֵ��ָ��ĺ���


// �������
// ������ list �� pos λ�ò���һ�� dt �Ľڵ�
int Insert_LinkList(LinkList* list, int pos, LinkNode* dt);

// ɾ�������� ɾ������ list �е� pos ���ڵ�
int Delete_LinkList(LinkList* list, int pos);

// ���������С
int GetSize_LinkList(LinkList* list);

// ��������: ����������ÿ���ڵ��е�ֵ
// �ڵ��е�ֵ�������û�ά���ģ���Ϊ��ܿ����ߣ���֪��������ʲô����
// ��ˣ���Ϊ��ܿ����ߣ���֪������δ�ӡ����
// �����û�֪����δ�ӡ����
// ����Ҫ�û��ṩһ����ӡ���������Ƿ������(�ص�),��������ͽ��� �ص�����
// ��ͬ��������ƺ�����ʱ�򣬷���ϰ���ǲ�һ��
// ���ú�����ǰ���ǣ�������ȷ��������ĸ�ʽ: ���޲������������������޷���ֵ��ʲô����ֵ
// ���ԣ���Ϊ����ṩ�ߣ����Ǳ���Ҫ�淶�����ӡ�����ĸ�ʽ
// ������� ����ָ������ �ķ�ʽ��ָ����ӡ�����ĸ�ʽ
// ���� ����ָ�����ͣ���������û����ʵ�ֵ� ��ӡ��������
int Print_LinkList(LinkList* list, PRINTNODE print);

// ���Һ���
// ������ list �в����Ƿ���ڽڵ� dt��������ڣ����ص�һ�γ��� dt ��λ��
// ��Ϊ��ܿ����ߣ���֪��������ʲô���ģ�����û�����Ƚ�
// �������û���ʵ��һ���ȽϺ��������Ƿ���������Ƚ�
// ͨ�����ʵ��  ����ָ������ �ķ�ʽ��ִ�бȽϺ����Ĺ��
int Find_LinkList(LinkList* list, LinkNode* dt, COMPARENODE compare);


// ��������
int Destory_LinkList(LinkList* list);