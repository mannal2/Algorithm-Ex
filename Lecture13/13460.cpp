#include <bits/stdc++.h>
using namespace std;

/*
원래 bfs로 red에서 O까지의 경로를 찾은다음 경로에서 방향회전을 얻어내어
횟수를 구하려 했지만 맵의 모양에 따라 파랑색공을 신경써야 하는 부분이 늘어나
이 방법은 포기함.
*/
string board[12];
bool vis[12][12][12][12];

int n, m;
int redX, redY;
int blueX, blueY;
int holeX, holeY;
int cnt = -1;

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> board[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'R') {
				redX = i; redY = j;
			}
			else if (board[i][j] == 'B') {
				blueX = i; blueY = j;
			}
			else if (board[i][j] == 'O') {
				holeX = i; holeY = j;
			}
		}
	}

	queue<tuple<int, int, int, int, int>> Q;
	Q.push({ redX, redY, blueX, blueY, 0 });
	vis[redX][redY][blueX][blueY] = true;
	while (!Q.empty()) {
		int rx, ry, bx, by, curCnt;
		tie(rx, ry, bx, by, curCnt) = Q.front(); Q.pop();

		if (board[rx][ry] == 'O') { //빨강공의 현재위치가 구멍이면
			if (cnt == -1) cnt = curCnt;
			else cnt = min(cnt, curCnt);
		}

		for (int dir = 0; dir < 4; dir++) {
			int rmc = 0, bmc = 0;
			int tmpRx = rx, tmpRy = ry, tmpBx = bx, tmpBy = by;

			while (board[tmpRx + dx[dir]][tmpRy + dy[dir]] != '#' && board[tmpRx][tmpRy]!='O') {
				tmpRx += dx[dir];
				tmpRy += dy[dir];
				rmc++; //빨간공이 벽에 닿기 직전, 현위치가 구멍이 아닐때까지 이동
			}
			while (board[tmpBx + dx[dir]][tmpBy + dy[dir]] != '#' && board[tmpBx][tmpBy]!='O') {
				tmpBx += dx[dir];
				tmpBy += dy[dir];
				bmc++; //파랑공이 벽에 닿기 직전, 현위치가 구멍이 아닐때까지 이동
			}
			if (board[tmpBx][tmpBy] == 'O') continue; //파랑공이 구멍에 있으면 스킵
			//이 if문이 아래 if문보다 위에 있어야 두 공이 동시에 홀에 들어갈때를
			//예외처리 가능하다
			if (tmpRx == tmpBx && tmpRy == tmpBy) { //두공이 같은 위치에 있을때
				if (rmc > bmc) {
					tmpRx -= dx[dir];
					tmpRy -= dy[dir];
					rmc--;
				}
				else {
					tmpBx -= dx[dir];
					tmpBy -= dy[dir];
					bmc--;
				}
			}
			//cout << "rmc:" << rmc << " bmc:" << bmc << "\n";
			//cout << "rx:" << tmpRx << " ry:" << tmpRy << " bx:" << tmpBx << " by:" << tmpBy << "\n";
			if (vis[tmpRx][tmpRy][tmpBx][tmpBy]) continue; //이미 방문한 적이 있으면 스킵
			if (rmc == 0 && bmc == 0) continue; //두 공이 모두 이동못했을때 스킵
			

			if (curCnt < 10) { //보드판 기울이는 횟수가 10미만일때만 추가
				vis[tmpRx][tmpRy][tmpBx][tmpBy] = true;
				Q.push({ tmpRx, tmpRy, tmpBx, tmpBy, curCnt + 1 });
			}

		}
	}
	cout << cnt;

}