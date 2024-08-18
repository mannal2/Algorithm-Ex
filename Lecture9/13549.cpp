#include <bits/stdc++.h>
using namespace std;

int dist[200002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	queue<pair<int, int>> Q;
	Q.push({ n, 0 });
	while (!Q.empty()) {
		auto P = Q.front(); Q.pop();
		int x = P.first;
		int t = P.second;
		int dx[] = {x + 1, x - 1, 2*x};
		int dt[] = { t + 1, t + 1, t };
		if (x == k) { //체크는 for문 밖에서 할것!!!
			cout << dist[x];
			break;
		}
		for (int i = 0; i < 3;i++) {
			int nx = dx[i];

			if (nx < 0 || nx>200000) continue;
			if (dist[nx] == 0 || dist[nx] > t) {
				dist[nx] = dt[i];
				Q.push({ nx, dt[i]});
			}
			
		}

	}
	
}