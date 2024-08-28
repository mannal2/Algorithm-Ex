#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int board[40][40];
int cnt;
vector<pair<int, int>> sticker[101];
vector<pair<int, int>> area;

bool rotate_check(int startX, int startY, int num, int dir) { //0 1 2 3  정방향에서 시계방향으로 90도씩 회전

	int rn, rm;
	rn = area[num].first;
	rm = area[num].second;

	for (auto P : sticker[num]) {
		int x = P.first;
		int y = P.second;

		if (dir == 0) {
			if (board[startX + x][startY + y] == 1) return false;
		}
		else if (dir == 1) {
			if (board[startX + y][startY + rn - 1 - x] == 1) return false;
		}
		else if (dir == 2) {
			if (board[startX + rn - 1 - x][startY + rm - 1 - y] == 1) return false;
		}
		else if (dir == 3) {
			if (board[startX + rm - 1 - y][startY + x] == 1) return false;
		}
	}

	for (auto P : sticker[num]) {
		int x = P.first;
		int y = P.second;
		
		if (dir == 0) {
			board[startX+x][startY+y] = 1;
		}
		else if (dir == 1) {
			board[startX+y][startY+rn - 1 - x] = 1;
		}
		else if (dir == 2) {
			board[startX+rn - 1 - x][startY+rm - 1 - y] = 1;
		}
		else if (dir == 3) {
			board[startX+rm - 1 - y][startY+x] = 1;
		}
	}
	cnt += sticker[num].size();
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for(int num=0;num<k;num++){
		int nn, mm;
		cin >> nn >> mm;
		area.push_back({ nn,mm });
		for (int i = 0; i < nn; i++) {
			for (int j = 0; j < mm; j++) {
				int a;
				cin >> a;
				if (a == 1) {
					sticker[num].push_back({ i,j });
				}
			}
		}
	}
	for (int num = 0; num < k; num++) {
		bool nextNum = false;
		for (int dir = 0; dir < 4; dir++) {
			int nn = dir % 2 == 0 ? area[num].first : area[num].second;
			int mm = dir % 2 == 0 ? area[num].second : area[num].first;
			for (int x = 0; x <= n - nn; x++) {
				for (int y = 0; y <= m - mm; y++) {
					if (rotate_check(x, y, num, dir)) {
						nextNum=true;
						break;
					}
				}
				if (nextNum) break;
			}
			if (nextNum)break;
		}
	}
	cout << cnt;
}