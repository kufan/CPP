// https://vjudge.net/problem/UVA-442
// (A(BC))
// 扫描字符串，遇到矩阵(其就是字母)则入栈
// 遇到 ')'，拿出当前栈顶元素当作 右操作数，再拿出一个元素作左操作数
// 乘法结果是一个新的矩阵，新矩阵入栈
// 直到字符串扫描结束，栈中仅剩的元素，就是计算结果
// 如果某个式子可以计算，则计算总的基础乘法次数


/*
一些常见且好用的函数：
	isdigit(c): 判断 c 是不是字符型数字： c >= '0' && c <= '9' 
	isalpha(c): 判断 c 是不是字母(包括大小写)
	isalnum(c): 判断 c 是不是字母(包括大小写)或者字符型数字
	isupper(c): 判断是不是大写
	islower(c): 判断是不是小写
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Mat {
	int a, b;  // a:行    b:列

	Mat(){}  // 默认构造函数
	Mat(int aa, int bb) {
		a = aa;
		b = bb;
	}
}m[30];
// Mat m[30];

stack<Mat> s;
int n;  // 有 n 个矩阵
char c;  // 矩阵的名字
string str;  // 待处理矩阵计算式
int ans;  // 表示基础乘法次数

bool flag;  // 标记某个式子是否可以计算

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c;
		int k = c - 'A';
		cin >> m[k].a >> m[k].b;
	}

	// 得到待处理的矩阵乘法式子
	while (cin >> str) {
		int len = str.size();
		flag = 1;  // 起始时，假设该式子可以计算
		ans = 0;

		for (int i = 0; i < len; i++) {
			if (isalpha(str[i])) {
				// 扫描到的每一个矩阵，一定在数组 mat 中
				s.push(m[str[i] - 'A']);
			} else if(str[i] == ')'){
				// 先取出右操作数
				Mat m2 = s.top();
				s.pop();

				// 然后取出左操作数
				Mat m1 = s.top();
				s.pop();

				if (m1.b != m2.a) {
					flag = 0;
					break;
				}

				// 基础乘法次数
				ans = ans + m1.a * m1.b * m2.b;
				// m1.a * m2.b
				s.push(Mat(m1.a, m2.b));
			}
		}


		if (flag) {
			cout << ans << endl;
		} else {
			cout << "error" << endl;
		}
	}
	
	return 0;
}
