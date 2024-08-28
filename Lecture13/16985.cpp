#include <bits/stdc++.h>
using namespace std;

int board[5][5][5]; // z x y
int dx[] = { 0,0,0,0,1,-1 };
int dy[] = { 0,0,1,-1,0,0 };
int dz[] = { 1,-1, 0,0,0,0 };
int vis[5][5][5];
int shortest = -1;

int arr[5][5][5];

void resetVis() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			fill(vis[i][j], vis[i][j]+5, -1);
		}
	}
}

int findWay() {
	if (board[0][0][0] != 1 || board[4][4][4] != 1) return -1;
	resetVis();
	queue<tuple<int, int, int>> Q;
	Q.push({ 0,0,0 });
	vis[0][0][0] = 0;
	while (!Q.empty()) {
		int z, x, y;		
		tie(z, x, y) = Q.front(); Q.pop();
		if (shortest != -1 && shortest <= vis[z][x][y]) continue;
		for (int dir = 0; dir < 6; dir++) {
			int nz = z + dz[dir];
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nz < 0 || nx < 0 || ny < 0 || nz >= 5 || nx >= 5 || ny >= 5) continue;
			if (board[nz][nx][ny] == 0 || vis[nz][nx][ny]!=-1) continue;
			vis[nz][nx][ny] = vis[z][x][y]+1;
			Q.push({ nz, nx, ny });
		}

	}
	return vis[4][4][4];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for (int k = 0; k < 5; k++) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				cin >> arr[k][i][j];
			}
		}
	}
	int num[] = { 0,1,2,3,4 };
	do {
		for (int a = 0; a < 1024;a++) {
			int index = 0;
			int r, tmp=a;
			while (index != 5) {
				r = tmp % 4;
				tmp = tmp / 4;
				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < 5; j++) {
						if (r == 0) board[index][i][j] = arr[num[index]][i][j];
						else if (r == 1) board[index][j][4-i] = arr[num[index]][i][j];
						else if (r == 2) board[index][4-i][4-j] = arr[num[index]][i][j];
						else if (r == 3) board[index][4-j][i] = arr[num[index]][i][j];
					}
				}
				index++;
			}
			tmp = findWay();
			if (shortest != -1 && tmp != -1) shortest = min(shortest, tmp);
			else if (shortest == -1) shortest = tmp;
		}
	} while (next_permutation(num, num + 5));

	cout << shortest;
}