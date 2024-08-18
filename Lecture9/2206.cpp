#include <bits/stdc++.h>
using namespace std;

string board[1002];
int dist[1002][1002][2];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	memset(dist, -1, sizeof(dist));

	queue<tuple<int, int, int>> Q;
	dist[0][0][0]=1;
	Q.push({ 0,0, 0 });
	while (!Q.empty()) {
		int xx, yy, bb;
		tie(xx, yy, bb) = Q.front(); Q.pop();
		if (xx == n - 1 && yy == m - 1) { //cout�� �ݺ��� �ȿ� ������ ���� �߻�
			cout << dist[xx][yy][bb]; //�Ƹ� �ݺ����� �� ������ �ּұ��̰� ���������� cout�� �ؾ��ϴ� ���
			return 0;
		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = xx + dx[dir];
			int ny = yy + dy[dir];
			
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			
			if (board[nx][ny] == '0' && dist[nx][ny][bb] == -1) { //�Ⱥμ�����
				dist[nx][ny][bb] = dist[xx][yy][bb]+1;
				Q.push({ nx, ny ,bb });
			}
			else if (board[nx][ny] == '1' && bb == 0 && dist[nx][ny][1] == -1) { //�μ�����
				dist[nx][ny][1] = dist[xx][yy][bb]+1;
				Q.push({ nx, ny ,1});
			}

		}
	}
	cout << "-1\n";

}

/* ���� �μ������� �Ⱥμ������� �������� �ʰ� �Ϸ��ٰ� ����
#include <bits/stdc++.h>
using namespace std;

string board[1002];
int dist[1002][1002];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	queue<tuple<int, int, int>> Q;
	dist[0][0] = 1;
	Q.push({ 0,0, 1 });
	while (!Q.empty()) {
		int xx, yy, bb;
		tie(xx, yy, bb) = Q.front(); Q.pop();

		int t = dist[xx][yy] + 1;
		for (int dir = 0; dir < 4; dir++) {
			int nx = xx + dx[dir];
			int ny = yy + dy[dir];

			if (nx == n - 1 && ny == m - 1) {
				cout << dist[xx][yy] + 1;
				return 0;
			}
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

			if (board[nx][ny] == '0' && (dist[nx][ny] == 0 || dist[nx][ny] > t)) {
				dist[nx][ny] = t;
				Q.push({ nx, ny ,bb });
			}
			else if (board[nx][ny] == '1' && bb == 1 && (dist[nx][ny] == 0 || dist[nx][ny] > t)) {
				dist[nx][ny] = t;
				Q.push({ nx, ny ,0 });
			}

		}
	}
	cout << "-1\n";

}*/