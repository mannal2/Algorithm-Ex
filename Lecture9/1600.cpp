#include <bits/stdc++.h>
using namespace std;

int board[202][202];
int dist[202][202][32];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int ddx[] = { -2,-1,1,2,2,1,-1,-2 };
int ddy[] = { 1,2,2,1,-1,-2,-2,-1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k, m, n;
	cin >> k;
	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	queue<tuple<int, int, int>> Q;
	Q.push({ 0,0,0});
	dist[0][0][0] = 1;

	while (!Q.empty()) {
		int x, y, mm;
		tie(x, y, mm) = Q.front(); Q.pop();

		if (x == n - 1 && y == m - 1) {
			cout << dist[x][y][mm]-1;
			return 0;
		}

		if (mm < k) { //말처럼 건너뛸수있는 횟수가 남아있을떄
			for (int dir = 0; dir < 8; dir++) {
				int nx = x + ddx[dir];
				int ny = y + ddy[dir];

				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (board[nx][ny] == 1 || dist[nx][ny][mm+1] !=0) continue;
				
				dist[nx][ny][mm + 1] = dist[x][y][mm] + 1;
				Q.push({ nx, ny, mm + 1 });
			}
		}
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == 1 || dist[nx][ny][mm] !=0) continue;

			dist[nx][ny][mm] = dist[x][y][mm] + 1;
			Q.push({ nx, ny, mm });
			
		}
		/*
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << dist[i][j] << " ";
			}
			cout << "\n";
		}*/

	}
	cout << -1;
}