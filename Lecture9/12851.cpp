#include <bits/stdc++.h>
using namespace std;

int vis[100001];
int dx[] = { -1, 1, 2 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	int cnt = 0, times;
	cin >> n >> m;
	queue<pair<int, int>> Q;
	
	Q.push({n, 1});
	if (n == m) {
		cout << "0\n1";
		return 0;
	}

	while (!Q.empty()) {
		pair<int, int> P = Q.front();
		int px = P.first;
		int t = P.second;
		Q.pop();
		for (int i = 0; i < 3; i++) {
			int nx;
			if (dx[i] == 2) nx = 2 * px;
			else nx = px + dx[i];

			if (nx < 0 || nx > 100000) continue;
			if (vis[nx] != 0 && t + 1 > vis[nx]) continue;
			else vis[nx] = t + 1;
			//보통 방문처리를 해서 풀이하는 방식이 많던데 그 방식은 이해가 되지 않아
			//새로운 방식으로 작성하였다.
			//1에서 4를 간다 할때 중간에 2를 가는 방법은 2가지 인데
			//2로 넘어가는 시간이 최소시간일때만 push하는 식으로 하니
			//다른 중복체크없이 진행할 수 있었다.
			//아마 이게 그리디 알고리즘의 최적부분구조 조건인것으로 기억함.

			Q.push({ nx, t + 1 });
			if (nx == m) {
				if (cnt == 0) times = vis[nx]-1;
				cnt++;
			}
		}
	}
	cout << times << "\n" << cnt;

}