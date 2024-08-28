#include <bits/stdc++.h>
using namespace std;

int board[50][50];
bool vis[50][50];
int n, m;
int dir, x, y;
int cnt = 0;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0 ,-1,0,1};

int dx2[] = { -1,0,1,0 };
int dy2[] = { 0,1,0,-1 };

void rotate() {
	dir = (dir + 3) % 4;
}

bool aroundClean() {
	int c = 0;
	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (board[nx][ny] == 1 || vis[nx][ny]) continue;
		c++;
	}
	if (c) return false;
	else return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	cin >> x >> y >> dir;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> board[i][j];
	}
	while (1) {
		if (board[x][y] == 0 && !vis[x][y]) {
			vis[x][y] = true;
			cnt++;
		}
		if (aroundClean()) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (board[nx][ny] == 1) break;
			else {
				x = nx; y = ny;
			}
		}
		else {
			rotate();
			int nx = x + dx2[dir];
			int ny = y + dy2[dir];
			if (board[nx][ny] == 0 && !vis[nx][ny]) {
				x = nx;
				y = ny;
			}
		}
	}
	cout << cnt;
}