#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dist[102][102];
string board[102];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
		fill(dist[i], dist[i] + m, -1);
	}
	
	queue<pair<int, int>> Q;
	dist[0][0] = 1;
	Q.push({ 0, 0 });
	while (!Q.empty()) {
		pair<int, int> P = Q.front(); Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = P.X + dx[i];
			int ny = P.Y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
			if (board[nx][ny] == '0' || dist[nx][ny] != -1)continue;
			dist[nx][ny] = dist[P.X][P.Y] + 1;
			Q.push({ nx, ny });
		}
	}
	cout << dist[n-1][m-1];

}