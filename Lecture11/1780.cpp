#include <bits/stdc++.h>
using namespace std;

int board[2200][2200];
int cnt[3];
int num[3] = { -1,0,1 };

void ffff(int x, int y, int n) {
	int gijun = board[x][y];
	bool check = true;
	for (int i = x; i < x+n; i++) {
		for (int j = y; j < y+n; j++) {
			if (gijun != board[i][j]) {
				check = false;
				break;
			}
		}
	}

	if (check) { //모두 동일하면
		for (int i = 0; i < 3; i++) {
			if (gijun == num[i]) {
				cnt[i]++;
				break;
			}
		}
	}
	else { //동일하지 않을때
		int temp = n / 3; //3
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				ffff(x+i*temp, y+j*temp, temp);
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
	ffff(0,0,n);
	for (int i = 0; i < 3; i++)
		cout << cnt[i] << "\n";

}