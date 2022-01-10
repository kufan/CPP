// https://vjudge.net/problem/UVA-455
#include <iostream>
#include <string>

using namespace std;

int n;
string s;
int len, mn;
// len: 表示每个样例(字符串)的长度  mn： 最小周期


// 判断 T 是不是 s 的周期
bool foo(int T) {
	for (int i = 0; i + T < len; i++) {
		if (s[i] != s[i+T]) {
			return false;
		}
	}
	return true;
}

int main()
{
	cin >> n;
	while (n--) {
		cin >> s;

		len = s.size();  // s.length()
		mn = len;  // 起始时，假设字符串 s 的周期就是 len

		// 从第二个元素开始判断，
		for (int i = 1; i <= len-1; i++) {
			// 判断 i 是不是周期
			if (len % i == 0 && foo(i)) {
				mn = i;
				break;
			}
		}

		cout << mn << endl;
		
		if (n) {
			// 确保样例和样例之间，有空行
			cout << endl;
		}
	}
	
	
	return 0;
}