#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long a, b;
	cin >> a >> b;
	if (a > b) { //swqp 함수로 대체
		long long temp = a; //temp 변수 또한 longlong으로 선언
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