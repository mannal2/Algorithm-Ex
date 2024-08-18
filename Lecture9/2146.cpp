#include <bits/stdc++.h>
using namespace std;

int board[102][102];
bool vis[102][102];
int dist[102][102];

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	set<int> S;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	int land = 2;
	for (int i = 0; i < n; i++) { //각 대륙마다 번호부여
		for (int j = 0; j < n; j++) {
			if (board[i][j] != 1 || vis[i][j]) continue;

			queue<pair<int, int>> Q;
			vis[i][j] = true;
			Q.push({ i, j });
			board[i][j] = land;

			while(!Q.empty()) {
				pair<int, int> P = Q.front(); Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = P.first + dx[dir];
					int ny = P.second + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (board[nx][ny] == 0 || vis[nx][ny]) continue;

					board[nx][ny] = land;
					vis[nx][ny] = true;
					Q.push({ nx, ny });
				}
			}
			land++;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 0) continue;
			land = board[i][j];
			queue<tuple<int, int, int>> Q;
			Q.push({ i, j, 0 });

			while (!Q.empty()) {
				int x, y, bb;
				tie(x, y, bb) = Q.front(); Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (board[nx][ny] != 0 && board[nx][ny] != land) { //새로운 대륙에 접근
						S.insert(bb);
					}
					else if (board[nx][ny] == 0) { //바다로 항해중
						if (dist[nx][ny] == 0 || dist[nx][ny] > bb + 1) {
							dist[nx][ny] = bb + 1;
							Q.push({ nx, ny, bb + 1 });
						}
					}
				}
			}
		}
	}
	cout << *S.begin();
}