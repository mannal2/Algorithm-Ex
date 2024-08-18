#include <bits/stdc++.h>
using namespace std;

char board[1002][1002];
int dist[1002][1002];
int dist2[1002][1002];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1, -1, 0, 0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	cin.ignore();
	queue<pair<int, int>> Q;
	queue<pair<int, int>> Q2;
	
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			board[i][j] = s[j];
			if (board[i][j] == 'J') {
				dist[i][j] = 1;
				Q.push({ i,j });
			}
			if (board[i][j] == 'F') {
				dist2[i][j] = 1;
				Q2.push({ i,j });
			}
			if (board[i][j] == '#') {
				dist[i][j] = -1;
				dist2[i][j] = -1;
			}
		}
	}

	while (!Q2.empty()) {
		pair<int, int> P = Q2.front(); Q2.pop();
		for (int i = 0; i < 4; i++) {
			int nx = P.first + dx[i];
			int ny = P.second + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist2[nx][ny] != 0) continue;
			dist2[nx][ny] = dist2[P.first][P.second]+1;
			Q2.push({ nx, ny });
		}
	}

	while (!Q.empty()) {
		pair<int, int> P = Q.front(); Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = P.first + dx[i];
			int ny = P.second + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				std::cout << dist[P.first][P.second];
				return 0;
			}
			if (dist[nx][ny] != 0) continue;
			if (dist2[nx][ny] <= dist[P.first][P.second] + 1 && dist2[nx][ny] !=0) continue; //불이 이동한 곳이 맞는지 체크하기 위해 !=0
			dist[nx][ny] = dist[P.first][P.second] + 1;
			Q.push({ nx, ny });
			
		}
	}
	std::cout << "IMPOSSIBLE";
}