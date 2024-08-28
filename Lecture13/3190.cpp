#include <bits/stdc++.h>
using namespace std;

int dir = 1;// ºÏ µ¿ ³² ¼­

int dx[] = { -1 , 0 , 1 , 0 };
int dy[] = { 0, 1, 0, -1 };

int board[102][102];
bool vis[102][102];
int n;

void turnLeft() {
	dir = (dir + 3) % 4;
}
void turnRight() {
	dir = (dir + 1) % 4;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k;
	int sec = 0;
	cin >> n;
	cin >> k;
	while (k--) {
		int a, b;
		cin >> a >> b;
		board[a][b] = 1;
	}
	deque<pair<int, int>> DQ;
	queue<pair<int, char>> Q;
	cin >> k;
	while (k--) {
		int a;
		char c;
		cin >> a >> c;
		Q.push({ a,c });
	}

	DQ.push_back({ 1,1 });
	vis[1][1] = true;
	int x = 1, y = 1;
	while (1) {
		sec++;
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx <= 0 || nx >n || ny <= 0 || ny > n || vis[nx][ny]) break;
		x = nx;
		y = ny;
		DQ.push_front({ x,y });
		vis[x][y] = true;
		if(board[x][y]==0){
			int xx, yy;
			tie(xx, yy) = DQ.back(); DQ.pop_back();
			vis[xx][yy] = false;
		}
		if (board[x][y] == 1) board[x][y] = 0;
		if (!Q.empty() && sec == Q.front().first) {
			auto P = Q.front(); Q.pop();
			if (P.second == 'L') turnLeft();
			else turnRight();
		}
	}
	cout << sec;
}