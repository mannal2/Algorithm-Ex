#include <bits/stdc++.h>
using namespace std;

#define old first
#define neww second

pair<int, int> board[302][302];
bool vis[302][302];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int n, m;


int getZero(int i, int j) {
	int cnt = 0;
	for (int dir = 0; dir < 4; dir++) {
		int nx = i + dx[dir];
		int ny = j + dy[dir];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (board[nx][ny].old == 0) cnt++;
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j].neww;
			board[i][j].old = board[i][j].neww;
		}
	}
	int t = 1;
	int abc = 2;
	while (1) {

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j].old > 0) {
					int a = board[i][j].old-getZero(i, j);
					a = a < 0 ? 0 : a;
					board[i][j].neww =  a;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				board[i][j].old = board[i][j].neww;
			}
		}

		int san = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j].neww > 0 && vis[i][j] == false) {
					san++;

					queue<pair<int, int>> Q;
					vis[i][j] = true;
					Q.push({ i, j });

					while (!Q.empty()) {
						pair<int, int> P = Q.front(); Q.pop();
						for (int dir = 0; dir < 4; dir++) {
							int nx = P.first + dx[dir];
							int ny = P.second + dy[dir];

							if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
							if (board[nx][ny].neww == 0 || vis[nx][ny]) continue;

							vis[nx][ny] = true;
							Q.push({ nx, ny });
						}
					}
				}
			}
		}
		if (san > 1) {
			cout << t;
			break;
		}
		else if (san == 0) {
			cout << 0;
			break;
		}
		for (int i = 0; i < 302; i++) 
			fill(vis[i], vis[i] + 302, false);
		t++;
	}

}