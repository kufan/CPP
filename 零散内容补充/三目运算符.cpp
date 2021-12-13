#include <iostream>

using namespace std;

int main() {
	// 一目运算符   单目 
	int a = 123;
	a++;
	a--;
	
	// 二目运算符   双目 
	int b = 321, c;
	c = a + b;  // +
	
	
	// 三目运算符 
	
	// a > b 是否为真？
	// 为真则取 a 的结果
	// 为假则取 b 的结果 
	c = a > b ? a : b;
	
	cout << c << endl; 
	
	return 0;
}
