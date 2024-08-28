#include <bits/stdc++.h>
using namespace std;

int cube[6]; // »ó ÇÏ ÁÂ ¿ì Àü ÈÄ
int x, y,n,m;
int board[20][20];

void moveCube(int dir) { //1234 µ¿ ¼­ ºÏ ³²
	if (dir == 1) {
		if (y + 1 >= m) return;
		int tmp = cube[2];
		cube[2] = cube[1]; 
		cube[1] = cube[3];
		cube[3] = cube[0];
		cube[0] = tmp;
		y++;
	}
	else if (dir == 2) {
		if (y - 1 < 0) return;
		int tmp = cube[3];
		cube[3] = cube[1];
		cube[1] = cube[2];
		cube[2] = cube[0];
		cube[0] = tmp;
		y--;
	}
	else if (dir == 3) {
		if (x - 1 < 0) return;
		int tmp = cube[0];
		cube[0] = cube[4];
		cube[4] = cube[1];
		cube[1] = cube[5];
		cube[5] = tmp;
		x--;
	}
	else {
		if (x + 1 >= n) return;
		int tmp = cube[5];
		cube[5] = cube[1];
		cube[1] = cube[4];
		cube[4] = cube[0];
		cube[0] = tmp;
		x++;
	}
	if (board[x][y] == 0) board[x][y] = cube[1];
	else {
		cube[1] = board[x][y];
		board[x][y] = 0;
	}
	cout << cube[0] << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k;
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	while (k--) {
		int a;
		cin >> a;
		moveCube(a);
	}

}