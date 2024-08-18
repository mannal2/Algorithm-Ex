#include <bits/stdc++.h>
using namespace std;

int board[1002][1002];
bool vis[1002][1002];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0, 1, 0, -1 };

void print(int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << vis[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	int tomato = 0;
	int delT = 0;
	int day=0;
	cin >> n >> m;
	queue<pair<int, int>> Q;
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1 || board[i][j] == 0) tomato++;
			if (board[i][j] == 1) {
				delT++;
				Q.push({ i, j });
				vis[i][j] = 1;
			}
		}
	}
	if (delT== tomato) {
		cout << 0;
		return 0;
	}
	while(1) {
		queue<pair<int, int>> Q2;
		while (!Q.empty()) {
			pair<int, int> P = Q.front(); Q.pop();
			for (int j = 0; j < 4; j++) {
				int nx = P.first + dx[j];
				int ny = P.second + dy[j];
				if (nx < 0 || nx >= m || ny < 0 || ny >= n)continue;
				if (board[nx][ny] == -1 || vis[nx][ny] == 1)continue;
				delT++;
				vis[nx][ny] = 1;
				Q2.push({ nx, ny });
			}
		}
		//print(m, n);
		Q = Q2;
		day++;
		if (delT == tomato || Q2.empty()) {
			break;
		}
	}
	if (delT == tomato)cout << day;
	else cout << -1;

}