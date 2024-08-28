#include <bits/stdc++.h>
using namespace std;

int n, m;
int maxNum = 0;

int dx[] = { 1,0,0 , -1}; //го аб ©Л ╩С
int dy[] = { 0,-1,1 , 0};

int dd[4][3] = {
	{1,2,3},{3,2,0},{0,1,2},{0,1,3}
};

int board[500][500];
bool vis[500][500];

void ffff(int x, int y, int k, int sum) {
	if (k == 4) {
		maxNum = max(maxNum, sum);
		return;
	}
	for (int dir = 0; dir < 3; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (vis[nx][ny]) continue;
		vis[nx][ny] = true;
		ffff(nx, ny, k + 1, sum + board[nx][ny]);
		vis[nx][ny] = false;
	}
}

void ffff2(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int sum = board[x][y];
		for (int j = 0; j < 3; j++) {
			int nx = x + dx[dd[i][j]];
			int ny = y + dy[dd[i][j]];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) break;
			sum += board[nx][ny];
		}
		maxNum = max(maxNum, sum);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> board[i][j];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			vis[i][j] = true;
			ffff(i, j, 1, board[i][j]);
			vis[i][j] = false;
			ffff2(i, j);
		}
	}
	cout << maxNum;
}