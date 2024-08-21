#include <bits/stdc++.h>
using namespace std;

char board[3200][6400];

void ffff(int x, int y, int n) {
	int yy = y - 1;
	if (n == 1) {
		board[x][yy] = '*';
		board[x + 1][yy - 1] = '*';
		board[x + 1][yy + 1] = '*';
		for (int i = 0; i < 5; i++)
			board[x + 2][yy - 2 + i] = '*';
	}
	else {
		ffff(x, y, n / 2);
		ffff(x+n/2*3, y - n/2*3, n / 2);
		ffff(x+n/2*3, y + n/2*3, n / 2);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		fill(board[i], board[i] + n * 2, ' ');
	}

	ffff(0, n, n/3);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n * 2; j++) {
			cout << board[i][j];
		}
		cout << "\n";
	}
}