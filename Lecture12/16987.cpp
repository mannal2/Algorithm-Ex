/*
1. ������ ���� ��� ������ �ε�ġ�� �Ѵ�.
2. �տ� ���� ����� ������ ����� �Ǹ� ����������� ���Ѵ�.

be�� ���������� �ΰ� brokenEgg��� ����<=0���� üũ�ϸ� ������ ���ϼ�����
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