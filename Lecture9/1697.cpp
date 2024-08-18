#include <bits/stdc++.h>
using namespace std;

int dist[100001];
int dx[] = { -1, 1, 2 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	queue<int> Q;
	dist[n] = 1;
	Q.push(n);
	if (n == m) cout << 0;
	while (!Q.empty()) {
		int px = Q.front(); Q.pop();
		for (int i = 0; i < 3; i++) {
			int nx;
			if (dx[i] == 2) nx = 2 * px;
			else nx = px + dx[i];

			if (nx < 0 || nx > 100000) continue;
			if (dist[nx] != 0) continue;

			dist[nx] = dist[px] + 1;
			Q.push(nx);
			if (nx == m) {
				cout << dist[nx] - 1;
				break;
			}
		}
	}

}