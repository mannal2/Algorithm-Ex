#include <bits/stdc++.h>
using namespace std;

string word[] = { "R", "G", "B", "RG" };
int cnt[4];
string board[102];
bool vis[102][102];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void reset() {
	for (int i = 0; i < 102; i++) {
		fill(vis[i], vis[i] + 102, false);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	for (int k = 0; k < 4; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (vis[i][j] == false && word[k].find(board[i][j]) != string::npos) {
					queue<pair<int, int>> Q;
					Q.push({ i, j });
					vis[i][j] = true;
					cnt[k]++;

					while (!Q.empty()) {
						pair<int, int> P = Q.front(); Q.pop();
						for (int dir = 0; dir < 4; dir++) {
							int nx = P.first + dx[dir];
							int ny = P.second + dy[dir];

							if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
							if (word[k].find(board[nx][ny]) == string::npos || vis[nx][ny]) continue;

							vis[nx][ny] = true;
							Q.push({ nx, ny });
						}
					}
				}
			}
		}
		reset();
	}
	cout << cnt[0] + cnt[1] + cnt[2] << " " << cnt[2] + cnt[3];
}