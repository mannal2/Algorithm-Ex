#include <bits/stdc++.h>
using namespace std;

string board[12];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void printBoard() {
	cout << "\n";
	for (int i = 0; i < 12; i++)
		cout << board[i] << "\n";
	cout << "\n";
}

void moveBoard() {
	
	for (int j = 0; j < 6; j++) {
		char tmp[12];
		int cnt = 0;
		fill(tmp, tmp + 12, '.');
		for (int i = 11; i > -1; i--) {
			if (board[i][j] == '.') continue;
			tmp[cnt++] = board[i][j];
		}
		for (int i = 0; i < 12; i++) {
			board[i][j] = tmp[11 - i];
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 12; i++)
		cin >> board[i];

	int sum = 0;
	while (1) {
		int cnt = 0;
		bool vis[12][6] = {};
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (board[i][j] == '.' || vis[i][j]) continue;

				queue<pair<int, int>> Q;
				vector<pair<int, int>> V;
				vis[i][j] = true;
				Q.push({ i,j });
				while (!Q.empty()) {
					auto P = Q.front(); Q.pop();
					V.push_back(P);

					for (int dir = 0; dir < 4; dir++) {
						int nx = P.first + dx[dir];
						int ny = P.second + dy[dir];

						if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
						if (board[nx][ny] != board[i][j] || vis[nx][ny]) continue;

						vis[nx][ny] = true;
						Q.push({ nx, ny });
					}
				}
				if (V.size() > 3) {
					for (auto P : V) board[P.first][P.second] = '.';
					cnt++;
				}
			}
		}
		if (cnt == 0) break;
		sum++;
		moveBoard();

	}
	cout << sum;
}