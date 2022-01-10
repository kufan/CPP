// https://www.luogu.com.cn/problem/P1739
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	char c;
	stack<char> s;

	// while (1) {
	//	cin >> c;
	//	if(c == '@') {
	//		break;
	//	}
	while(cin >> c && c != '@') {
		if (c == '(') {
			s.push(c);
		}
		if (c == ')') {
			if (s.empty()) {
				cout << "NO" << endl;
				return 0;
			} else {
				s.pop();
				// 弹出栈顶元素，与当前的 ) 匹配
			}
		}
	}

	if (s.empty()) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	
	
	return 0;
}