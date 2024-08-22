#include <bits/stdc++.h>
using namespace std;

int n;
int cnt = 0;
bool isUsed1[15];
bool isUsed2[30];
bool isUsed3[30];

void ffff(int k) {
	if (k == n) {
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (isUsed1[i] || isUsed2[k + i] || isUsed3[k - i + n - 1]) continue;
		isUsed1[i] = 1;
		isUsed2[k + i] = 1;
		isUsed3[k - i + n - 1] = 1;
		ffff(k + 1);
		isUsed1[i] = 0;
		isUsed2[k + i] = 0;
		isUsed3[k - i + n - 1] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	ffff(0);
	cout << cnt;
}