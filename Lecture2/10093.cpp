#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long a, b;
	cin >> a >> b;
	if (a > b) { //swqp �Լ��� ��ü
		long long temp = a; //temp ���� ���� longlong���� ����
		a = b;
		b = temp;
	}
	if (b - a > 1) {
		cout << b - a - 1 << "\n";
		for (long long i = a + 1; i < b; i++) {
			cout << i << " ";
		}
	}
	else
		cout << 0;
	

}