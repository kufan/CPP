#include <iostream>

using namespace std;

int main() {
	// һĿ�����   ��Ŀ 
	int a = 123;
	a++;
	a--;
	
	// ��Ŀ�����   ˫Ŀ 
	int b = 321, c;
	c = a + b;  // +
	
	
	// ��Ŀ����� 
	
	// a > b �Ƿ�Ϊ�棿
	// Ϊ����ȡ a �Ľ��
	// Ϊ����ȡ b �Ľ�� 
	c = a > b ? a : b;
	
	cout << c << endl; 
	
	return 0;
}
