#include <bits/stdc++.h>
using namespace std;

int board[102][102];

int dx[] = { 0,-1,0,1 }; //우 상 좌 하
int dy[] = { 1,0,-1,0 };

void dragon(int startX, int startY, int dir, int gen) {
	int cnt = 0;
	vector<pair<int, int>> V;
	V.push_back({ startX, startY });
	board[startX][startY] = 1;
	V.push_back({ startX + dx[dir], startY + dy[dir] });
	board[startX + dx[dir]][ startY + dy[dir]] = 1;

	/*
	i+1 -> j-1
	j-1 -> i-1
	i-1 -> j+1
	j+1 -> i+1
	시계방향으로 90도 회전시 좌표가 바뀌는 공식
	*/


	while (cnt != gen) {
		int size = V.size()-1;
		for (int i = size; i > 0; i--) {
			int ddx = V[i - 1].first- V[i].first; //두 위치의 차이를 구함
			int ddy = V[i - 1].second- V[i].second;
			for (int j = 0; j < 4; j++) {
				if (ddx == dx[j] && ddy == dy[j]) {//시계방향으로 90도 돌렸을때의 위치를 구함
					int ddir = (j + 3) % 4;
					int nx = V[V.size() - 1].first + dx[ddir];
					int ny = V[V.size() - 1].second + dy[ddir];
					V.push_back({ nx, ny });
					board[nx][ny] = 1;
					break;
				}
			}
		}
		cnt++;
	}

	//출력부
	/*
	for (int i = V.size() - 1; i >= 0; i--) {
		cout << "x:" << V[i].first << " y:" << V[i].second << "\n";
	}
	*/
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,sum=0;
	cin >> n;
	while (n--) {
		int ii, jj, dir, gen;
		cin >> jj >> ii >> dir >> gen;
		dragon(ii, jj, dir, gen);
	}
	for (int i = 0; i <= 99; i++) {
		for (int j = 0; j <= 99; j++) {
			if (board[i][j] == 1 && board[i][j + 1] == 1
				&& board[i + 1][j] == 1 && board[i + 1][j + 1] == 1) {
				sum++;
			}
		}
	}
	cout << sum;
}