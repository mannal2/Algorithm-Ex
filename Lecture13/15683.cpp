#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[10][10];
int minSagak = 100;
int cnt;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0, -1, 1 };

int dir2[2][2] = { {0,1},{2,3} };
int dir3[4][2] = { {0,3},{1,3},{1,2},{0,2} };
int dir4[4][3] = { {2,0,3},{0,3,1}, {3,1,2}, {1,2,0} };
int dir5[] = { 0,1,2,3 };
vector<pair<int, int>> V;

void gamsi(int x, int y, int dir) { //0 1 2 3 ╩С го аб ©Л
	while (1) {
		x += dx[dir];
		y += dy[dir];
		if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] == 6) break;
		if (board[x][y] == 0) {
			board[x][y] = -1;
			cnt--;
		}
		else if (board[x][y] < 0) board[x][y]--;
	}
}

void re_gamsi(int x, int y, int dir) { //0 1 2 3 ╩С го аб ©Л
	while (1) {
		x += dx[dir];
		y += dy[dir];
		if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] == 6) break;
		if (board[x][y] == -1) {
			board[x][y] = 0;
			cnt++;
		}
		else if (board[x][y] < -1) board[x][y]++;
	}
}

void ffff(int k) {
	if (k == V.size()) {
		minSagak = min(minSagak, cnt);
		return;
	}
	auto P = V[k];
	int x = P.first;
	int y = P.second;
	if (board[x][y] == 1) {
		for (int i = 0; i < 4; i++) {
			gamsi(x, y, i);
			ffff(k + 1);
			re_gamsi(x, y, i);
		}
	}
	else if (board[x][y] == 2) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) gamsi(x, y, dir2[i][j]);
			ffff(k + 1);
			for (int j = 0; j < 2; j++) re_gamsi(x, y, dir2[i][j]);
		}
	}
	else if (board[x][y] == 3) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 2; j++) gamsi(x, y, dir3[i][j]);
			ffff(k + 1);
			for (int j = 0; j < 2; j++) re_gamsi(x, y, dir3[i][j]);
		}
	}
	else if (board[x][y] == 4) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 3; j++) gamsi(x, y, dir4[i][j]);
			ffff(k + 1);
			for (int j = 0; j < 3; j++) re_gamsi(x, y, dir4[i][j]);
		}
	}
	else if (board[x][y] == 5) {
		for (int i = 0; i < 4; i++) gamsi(x, y, i);
		ffff(k + 1);
		for (int i = 0; i < 4; i++) re_gamsi(x, y, i);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) cnt++;
			if (board[i][j] >= 1 && board[i][j] <= 5) V.push_back({ i,j });
		}
	}
	ffff(0);
	cout << minSagak;
}