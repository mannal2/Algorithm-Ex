#include <bits/stdc++.h>
using namespace std;

/*
���� bfs�� red���� O������ ��θ� ã������ ��ο��� ����ȸ���� ����
Ƚ���� ���Ϸ� ������ ���� ��翡 ���� �Ķ������� �Ű��� �ϴ� �κ��� �þ
�� ����� ������.
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

		if (board[rx][ry] == 'O') { //�������� ������ġ�� �����̸�
			if (cnt == -1) cnt = curCnt;
			else cnt = min(cnt, curCnt);
		}

		for (int dir = 0; dir < 4; dir++) {
			int rmc = 0, bmc = 0;
			int tmpRx = rx, tmpRy = ry, tmpBx = bx, tmpBy = by;

			while (board[tmpRx + dx[dir]][tmpRy + dy[dir]] != '#' && board[tmpRx][tmpRy]!='O') {
				tmpRx += dx[dir];
				tmpRy += dy[dir];
				rmc++; //�������� ���� ��� ����, ����ġ�� ������ �ƴҶ����� �̵�
			}
			while (board[tmpBx + dx[dir]][tmpBy + dy[dir]] != '#' && board[tmpBx][tmpBy]!='O') {
				tmpBx += dx[dir];
				tmpBy += dy[dir];
				bmc++; //�Ķ����� ���� ��� ����, ����ġ�� ������ �ƴҶ����� �̵�
			}
			if (board[tmpBx][tmpBy] == 'O') continue; //�Ķ����� ���ۿ� ������ ��ŵ
			//�� if���� �Ʒ� if������ ���� �־�� �� ���� ���ÿ� Ȧ�� ������
			//����ó�� �����ϴ�
			if (tmpRx == tmpBx && tmpRy == tmpBy) { //�ΰ��� ���� ��ġ�� ������
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
			if (vis[tmpRx][tmpRy][tmpBx][tmpBy]) continue; //�̹� �湮�� ���� ������ ��ŵ
			if (rmc == 0 && bmc == 0) continue; //�� ���� ��� �̵��������� ��ŵ
			

			if (curCnt < 10) { //������ ����̴� Ƚ���� 10�̸��϶��� �߰�
				vis[tmpRx][tmpRy][tmpBx][tmpBy] = true;
				Q.push({ tmpRx, tmpRy, tmpBx, tmpBy, curCnt + 1 });
			}

		}
	}
	cout << cnt;

}