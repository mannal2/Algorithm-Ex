#include <bits/stdc++.h>
using namespace std;

int board[10][10];
int tmp[10][10];
int n, m, maxArea=0;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,-1,1 };

void virus() {
	bool vis[10][10] = {};
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] != 2 || vis[i][j]) continue;

			queue<pair<int, int>> Q;
			Q.push({ i, j });
			vis[i][j] = 1;
			while (!Q.empty()) {
				auto P = Q.front(); Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = P.first + dx[dir];
					int ny = P.second + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if(board[nx][ny] != 0 || vis[nx][ny]) continue;

					vis[nx][ny] = 1;
					board[nx][ny] = 2;
					Q.push({ nx, ny });
				}
			}
		}
	}
}

int getSafetyZone() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0) cnt++;
		}
	}
	return cnt;
}

void printBoard() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	vector<int> V;
	vector<int> VV;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tmp[i][j];
			if (tmp[i][j] == 0) V.push_back(i * m + j);
		}
	}
	for (int i = 0; i < V.size(); i++)VV.push_back(i < 3 ? 0 : 1);

	do {
		copy(&tmp[0][0], &tmp[0][0] + 100, &board[0][0]);
		for (int i = 0; i < VV.size(); i++) {
			if (VV[i] == 0) board[V[i] / m][V[i] % m] = 1;
		}
		virus();
		maxArea = max(maxArea, getSafetyZone());

	} while (next_permutation(VV.begin(), VV.end()));
	cout << maxArea;
}