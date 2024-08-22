#include <bits/stdc++.h>
using namespace std;

string board[5];
int dx[] = { -1,0,0,1 };
int dy[] = { 0,-1,1,0 };
int cnt;

/*
1. 25���� ���� 7�� ����
2. 7���� �ټ��� 4���̻����� Ȯ��
3. 7���� �̾����ִ��� üũ
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
		//7�� ���� ����
		for (int i = 0; i < 25; i++) {
			if (V[i] == 0) {
				princess.push_back(i);
			}
		}
		//�ټ��̰� 4���̻����� üũ
		int dasom = 0;
		for (int num : princess) {
			if (board[num / 5][num % 5] == 'S') dasom++;
			sevens[num / 5][num % 5] = true;
		}
		if (dasom < 4) continue;
		//7���� �̾����ִ��� üũ

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
1.�� 25ĭ�� ���������� ��Ʈ��ŷ�� ����
2.������ �����Ǹ� ����ĭ���� �̵��ϸ� ĥ���ָ� �ϼ�
3. ������ �ߺ��� �ذ����� ���ϴ� ���� �߻�

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