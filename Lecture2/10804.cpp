#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a[20];
	for (int i = 0; i < 20; i++) {
		a[i] = i + 1;
	}
	int b, c, cnt;
	for (int i = 0; i < 10; i++) {
		cin >> b >> c;
		cnt = (c-b + 1) / 2;
		for (int j = 0; j < cnt; j++) {
			int tmp = a[b-1 + j];
			a[b-1+j]=a[c-1 - j];
			a[c-1 - j] = tmp;
		}
	}
	for (int i = 0; i < 20; i++) cout << a[i] << " ";
}