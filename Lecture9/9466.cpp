#include <bits/stdc++.h>
using namespace std;

int board[100002];
bool vis[100002];

int check[100002];

void resets() {
	fill(check, check + 100002, 0);
}

void reset() {
	fill(board, board + 100002, 0);
	fill(vis, vis + 100002, false);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, n;
	cin >> t;
	while (t--) {
		reset();
		int cnt = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> board[i];
			check[board[i]]++;
			if (i == board[i]) { //3-3 4-4과 같이 자신의 수가 입력일때
				cnt++;
				vis[i] = true;
			}
			if (vis[board[i]]) { //5-3과 같이 끝이 정해진 수일때
				vis[i] = true;
			}
		}

		vector<int> nums;
		for (int k = 1; k <= n; k++) {
			if (vis[k] || vis[board[k]]) {
				vis[k] = true;
				continue;
			}
			queue<pair<int, int>> Q;
			Q.push({ k, k });
			nums.push_back(k);
			check[k] = k;

			while (!Q.empty()) {
				pair<int, int> P = Q.front(); Q.pop();
				int nx = board[P.first];

				if (vis[nx] == true) {
					for (int a : nums) vis[a] = true;
					nums.clear();
					break;
				}
				if (nx == P.second) { //목표지와 해당위치가 같을때
					cnt += nums.size();
					for (int a : nums) vis[a] = true;
					nums.clear();
					break;
				}
				else if (check[nx] == k) { //1 3 3 3 와 같이 계속 같은곳을 방문할때
					nums.clear();
					break;
				}
				else { // 1 2 3 4 계속 다른곳으로 이동
					nums.push_back(nx);
					check[nx] = k;
					Q.push({ nx, P.second });
				}
			}
		}
		cout << n - cnt << "\n";
		
	}

}