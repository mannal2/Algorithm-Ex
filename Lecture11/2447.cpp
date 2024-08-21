#include <bits/stdc++.h>
using namespace std;

char board[2200][2200];

void ffff(int x, int y, int n) {
	
	if (n == 3) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == 1 && j == 1) continue;
				else board[x+i][y+j] = '*';
			}
		}
	}
	else { //동일하지 않을때
		int temp = n / 3; //3
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == 1 && j == 1) continue;
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

	for (int i = 0; i < 2200; i++) {
		fill(board[i], board[i] + 2200, ' ');
	}

	ffff(0,0,n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j];
		}
		cout << "\n";
	}
}