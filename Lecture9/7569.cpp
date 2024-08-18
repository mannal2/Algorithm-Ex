#include <bits/stdc++.h>
using namespace std;

int board[102][102][102];
int dist[102][102][102];
int dx[] = { 1,0,-1,0 , 0, 0};
int dy[] = { 0, 1, 0, -1, 0, 0 };
int dz[] = { 0, 0, 0, 0, 1, -1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int m, n, h;
	cin >> m >> n >> h;
	queue<tuple<int, int, int>> Q;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> board[i][j][k];
				if (board[i][j][k] == 1) {
					Q.push({ i, j, k });
				}
				if (board[i][j][k] == 0) {
					dist[i][j][k] = -1;
				}
			}
		}
	}

	while (!Q.empty()) {
		tuple<int, int, int> pos = Q.front(); Q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = get<0>(pos) + dx[i];
			int ny = get<1>(pos) + dy[i];
			int nz = get<2>(pos) + dz[i];

			if (nx < 0 || nx >= h || ny < 0 || ny >= n || nz < 0 || nz >= m) continue;
			if (dist[nx][ny][nz] >=0) continue;

			dist[nx][ny][nz] = dist[get<0>(pos)][get<1>(pos)][get<2>(pos)] + 1;
			Q.push({ nx, ny, nz });
		}
	}

	int cnt = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (dist[i][j][k] == -1) {
					cout << -1;
					return 0;
				}
				cnt = max(cnt, dist[i][j][k]);
			}
		}
	}
	cout << cnt;

}