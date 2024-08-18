#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[501][501];
bool vis[501][501];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	int cnt = 0, maxN = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1 && vis[i][j] != 1) { //방문하지 않은 그림의 첫번째 칸
				int room = 1;
				cnt++;
				queue<pair<int, int>> Q;
				vis[i][j] = 1; //첫칸 방문 표시
				Q.push({ i, j });

				while (!Q.empty()) {
					pair<int, int> p = Q.front(); Q.pop();
					for (int k = 0; k < 4; k++) {
						int nextX = p.X + dx[k];
						int nextY = p.Y + dy[k];
						if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) continue;
						if (board[nextX][nextY] == 0 || vis[nextX][nextY] == 1) continue;
						vis[nextX][nextY] = 1;
						room++;
						Q.push({ nextX, nextY });
					}
				}

				maxN = room > maxN ? room : maxN;
			}
		}
	}

	cout << cnt << "\n" << maxN;

}