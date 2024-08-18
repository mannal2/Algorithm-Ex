#include <bits/stdc++.h>
using namespace std;

int dist[302][302];

int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

void reset() {
	for (int i = 0; i < 302; i++) fill(dist[i], dist[i] + 302, 0);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k, n, startx, starty, endx, endy;
	cin >> k;
	while (k--) {
		cin >> n;
		cin >> starty >> startx;
		cin >> endy >> endx;

		bool next = false;
		if (starty == endy && startx == endx) {
			cout << "0\n";
			continue;
		}

		dist[startx][starty] = 1;
		queue<pair<int, int>> Q;
		Q.push({ startx, starty });
		while (!Q.empty()) {
			pair<int, int> P = Q.front(); Q.pop();
			for (int dir = 0; dir < 8; dir++) {
				int nx = P.first + dx[dir];
				int ny = P.second + dy[dir];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (dist[nx][ny] != 0) continue;
				if (nx == endx && ny == endy) {
					cout << dist[P.first][P.second]<<"\n";
					next = true;
					break;
				}
				dist[nx][ny] = dist[P.first][P.second] + 1;
				Q.push({ nx, ny });
			}
			if (next)break;
		}
		reset();
	}
}