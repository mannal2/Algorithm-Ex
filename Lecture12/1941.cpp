#include <bits/stdc++.h>
using namespace std;

string board[5];
int dx[] = { -1,0,0,1 };
int dy[] = { 0,-1,1,0 };
int cnt;

/*
1. 25명중 랜덤 7명 선정
2. 7명중 다솜이 4명이상인지 확인
3. 7명이 이어져있는지 체크
*/

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> V;

	for (int i = 0; i < 5; i++)
		cin >> board[i];

	for (int i = 0; i < 25; i++) {
		V.push_back(i < 7 ? 0 : 1);
	}

	do{
		vector<int> princess;
		bool vis[5][5] = {};
		bool sevens[5][5] = {};
		int people = 0;
		//7명 조합 선정
		for (int i = 0; i < 25; i++) {
			if (V[i] == 0) {
				princess.push_back(i);
			}
		}
		//다솜이가 4명이상인지 체크
		int dasom = 0;
		for (int num : princess) {
			if (board[num / 5][num % 5] == 'S') dasom++;
			sevens[num / 5][num % 5] = true;
		}
		if (dasom < 4) continue;
		//7명이 이어져있는지 체크

		int first = princess[0];
		queue<pair<int, int>> Q;
		vis[first / 5][first % 5] = true;
		Q.push({ first / 5, first % 5 });

		while (!Q.empty()) {
			auto P = Q.front(); Q.pop();
			people++;
			for (int dir = 0; dir < 4; dir++) {
				int nx = P.first + dx[dir];
				int ny = P.second + dy[dir];

				if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
				if (vis[nx][ny]) continue;
				if (!sevens[nx][ny]) continue;

				vis[nx][ny] = true;
				Q.push({ nx, ny });
			}
		}

		if (people == 7) cnt++;

		
	} while (next_permutation(V.begin(), V.end()));
	cout << cnt;
}

/*
1.각 25칸을 시작점으로 백트래킹을 시작
2.조건이 만족되면 인접칸으로 이동하며 칠공주를 완성
3. 하지만 중복을 해결하지 못하는 문제 발생

string board[5];
bool isVis[5][5];
int cnt;
int dx[] = { -1,0,0,1};
int dy[] = { 0,-1,1,0 };
int arr[7];
set<int> S;

void ffff(int xx, int yy, int s, int y) {
	if (s == 7 && y <= 3) {
		cnt++;
		int sum = 0;
		for (int i = 0; i < 7; i++) {
			cout << "x:" << arr[i] / 5 << " y:" << arr[i] % 5 << "\n";
			sum += arr[i];
		}
		S.insert(sum);
		cout << "\n";
		return;
	}
	else if (s == 7) return;

	for (int i = 0; i < 4; i++) {
		int nx = xx + dx[i];
		int ny = yy + dy[i];
		if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
		if (isVis[nx][ny]) continue;
		//if (arr[s - 1] >= nx * 5 + ny) continue;
		arr[s] = nx * 5 + ny;
		if (board[nx][ny] == 'S') {
			isVis[nx][ny] = true;
			ffff(nx, ny, s + 1, y);
			isVis[nx][ny] = false;
		}
		else if(board[nx][ny]=='Y' && y<3){
			isVis[nx][ny] = true;
			ffff(nx, ny, s + 1, y + 1);
			isVis[nx][ny] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; i++)
		cin >> board[i];

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			arr[0] = i * 5 + j;
			if (board[i][j] == 'S') {
				isVis[i][j] = true;
				ffff(i, j, 1, 0);
				isVis[i][j] = false;
			}
			else {
				isVis[i][j] = true;
				ffff(i, j, 1, 1);
				isVis[i][j] = false;
			}
		}
	}
	//cout << cnt;
	cout << S.size();
}*/