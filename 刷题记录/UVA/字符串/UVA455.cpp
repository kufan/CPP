// https://vjudge.net/problem/UVA-455
#include <iostream>
#include <string>

using namespace std;

int n;
string s;
int len, mn;
// len: ��ʾÿ������(�ַ���)�ĳ���  mn�� ��С����


// �ж� T �ǲ��� s ������
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
		mn = len;  // ��ʼʱ�������ַ��� s �����ھ��� len

		// �ӵڶ���Ԫ�ؿ�ʼ�жϣ�
		for (int i = 1; i <= len-1; i++) {
			// �ж� i �ǲ�������
			if (len % i == 0 && foo(i)) {
				mn = i;
				break;
			}
		}

		cout << mn << endl;
		
		if (n) {
			// ȷ������������֮�䣬�п���
			cout << endl;
		}
	}
	
	
	return 0;
}