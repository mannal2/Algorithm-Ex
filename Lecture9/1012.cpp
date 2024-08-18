#include <bits/stdc++.h>
using namespace std;

int board[52][52];
bool vis[52][52] = { false };
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1, 0, 0 };

void print(int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}

void reset() {
	for (int i = 0; i < 52; i++) {
		fill(board[i], board[i] + 52, 0);
		fill(vis[i], vis[i] + 52, false);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, m, n, w, y, x;
	cin >> t;

	while (t--) {
		cin >> m >> n >> w;
		int cnt = 0;
		while (w--) {
			cin >> x >> y;
			board[y][x] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (vis[i][j] == false && board[i][j] == 1) {
					queue<pair<int, int>> Q;
					Q.push({ i, j });
					vis[i][j] = true;
					cnt++;

					while (!Q.empty()) {
						pair<int, int> P = Q.front(); Q.pop();
						for (int dir = 0; dir < 4; dir++) {
							int nx = P.first + dx[dir];
							int ny = P.second + dy[dir];

							if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
							if (vis[nx][ny] == true || board[nx][ny] == 0) continue;

							vis[nx][ny] = true;
							Q.push({ nx, ny });
						}
					}
				}
			}
		}
		cout << cnt << "\n";
		reset();
	}
}