// https://vjudge.net/problem/UVA-442
// (A(BC))
// ɨ���ַ�������������(�������ĸ)����ջ
// ���� ')'���ó���ǰջ��Ԫ�ص��� �Ҳ����������ó�һ��Ԫ�����������
// �˷������һ���µľ����¾�����ջ
// ֱ���ַ���ɨ�������ջ�н�ʣ��Ԫ�أ����Ǽ�����
// ���ĳ��ʽ�ӿ��Լ��㣬������ܵĻ����˷�����


/*
һЩ�����Һ��õĺ�����
	isdigit(c): �ж� c �ǲ����ַ������֣� c >= '0' && c <= '9' 
	isalpha(c): �ж� c �ǲ�����ĸ(������Сд)
	isalnum(c): �ж� c �ǲ�����ĸ(������Сд)�����ַ�������
	isupper(c): �ж��ǲ��Ǵ�д
	islower(c): �ж��ǲ���Сд
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Mat {
	int a, b;  // a:��    b:��

	Mat(){}  // Ĭ�Ϲ��캯��
	Mat(int aa, int bb) {
		a = aa;
		b = bb;
	}
}m[30];
// Mat m[30];

stack<Mat> s;
int n;  // �� n ������
char c;  // ���������
string str;  // ������������ʽ
int ans;  // ��ʾ�����˷�����

bool flag;  // ���ĳ��ʽ���Ƿ���Լ���

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c;
		int k = c - 'A';
		cin >> m[k].a >> m[k].b;
	}

	// �õ�������ľ���˷�ʽ��
	while (cin >> str) {
		int len = str.size();
		flag = 1;  // ��ʼʱ�������ʽ�ӿ��Լ���
		ans = 0;

		for (int i = 0; i < len; i++) {
			if (isalpha(str[i])) {
				// ɨ�赽��ÿһ������һ�������� mat ��
				s.push(m[str[i] - 'A']);
			} else if(str[i] == ')'){
				// ��ȡ���Ҳ�����
				Mat m2 = s.top();
				s.pop();

				// Ȼ��ȡ���������
				Mat m1 = s.top();
				s.pop();

				if (m1.b != m2.a) {
					flag = 0;
					break;
				}

				// �����˷�����
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
