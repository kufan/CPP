#include "match.h"

MyChar* CreateMyChar(char* p, int idx) {
	MyChar* my = NULL;

	my = (MyChar*)malloc(sizeof(MyChar));
	if (NULL == my) {
		perror("malloc");
		return NULL;
	}
	
	my->pAddr = p;
	my->index = idx;

	return my;
}

bool IsLeft(char c) {
	return c == '(';
}

bool IsRight(char c) {
	return c == ')';
}

// ���ַ��� str �� pos λ�õķ���ƥ��ʧ��
void ShowError(char* str, int pos) {
	std::cout << str << std::endl;
	int a = 24;
	for (int i = 0; i < pos; i++) {
		std::cout << " ";
	}
	std::cout << (char)a << std::endl;
}