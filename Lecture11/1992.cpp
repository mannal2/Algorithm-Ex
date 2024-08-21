#include <bits/stdc++.h>
using namespace std;

string board[130];
char num[2] = { '0','1' };

void ffff(int x, int y, int n) {
	char gijun = board[x][y];
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
		cout << gijun;
		return;
	}
	else { //동일하지 않을때
		int temp = n / 2; 
		cout << "(";
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				ffff(x + i * temp, y + j * temp, temp);
			}
		}
		cout << ")";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	ffff(0, 0, n);


}