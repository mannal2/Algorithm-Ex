/*
1. 깨지지 않은 계란 선택후 부딪치게 한다.
2. 손에 집은 계란이 마지막 계란이 되면 깨진계란수를 구한다.

be는 전역변수로 두고 brokenEgg대신 내구<=0으로 체크하면 변수를 줄일수있음
*/

#include <bits/stdc++.h>
using namespace std;

int maxEgg = 0;
bool brokenEgg[10];
int board[10][2];
int n;

void ffff(int k, int be) {
	if (k == n || be == n) {
		maxEgg = max(maxEgg, be);
		return;
	}
	if (brokenEgg[k] || be==n-1) {
		ffff(k + 1, be);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (k == i) continue;
		if (brokenEgg[i]) continue;

		board[k][0] -= board[i][1];
		board[i][0] -= board[k][1];
		if (board[k][0] <= 0) {
			brokenEgg[k] = true;
			be++;
		}
		if (board[i][0] <= 0) {
			brokenEgg[i] = true;
			be++;
		}
		ffff(k + 1, be);
		if (board[k][0] <= 0) {
			brokenEgg[k] = false;
			be--;
		}
		if (board[i][0] <= 0) {
			brokenEgg[i] = false;
			be--;
		}
		board[k][0] += board[i][1];
		board[i][0] += board[k][1];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> board[i][0] >> board[i][1];
	}
	ffff(0, 0);
	cout << maxEgg;
}