#include <bits/stdc++.h>
using namespace std;

int board[130][130];
int cnt[2];
int num[2] = { 0,1 };

void ffff(int x, int y, int n) {
	int gijun = board[x][y];
	bool check = true;
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (gijun != board[i][j]) {
				check = false;
				break;
			}
		}
	}

	if (check) { //모두 동일하면
		for (int i = 0; i < 2; i++) {
			if (gijun == num[i]) {
				cnt[i]++;
				break;
			}
		}
	}
	else { //동일하지 않을때
		int temp = n / 2; //3
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				ffff(x + i * temp, y + j * temp, temp);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	ffff(0, 0, n);
	for (int i = 0; i < 2; i++)
		cout << cnt[i] << "\n";

}