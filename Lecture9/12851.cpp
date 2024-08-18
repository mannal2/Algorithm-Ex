#include <bits/stdc++.h>
using namespace std;

int vis[100001];
int dx[] = { -1, 1, 2 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	int cnt = 0, times;
	cin >> n >> m;
	queue<pair<int, int>> Q;
	
	Q.push({n, 1});
	if (n == m) {
		cout << "0\n1";
		return 0;
	}

	while (!Q.empty()) {
		pair<int, int> P = Q.front();
		int px = P.first;
		int t = P.second;
		Q.pop();
		for (int i = 0; i < 3; i++) {
			int nx;
			if (dx[i] == 2) nx = 2 * px;
			else nx = px + dx[i];

			if (nx < 0 || nx > 100000) continue;
			if (vis[nx] != 0 && t + 1 > vis[nx]) continue;
			else vis[nx] = t + 1;
			//���� �湮ó���� �ؼ� Ǯ���ϴ� ����� ������ �� ����� ���ذ� ���� �ʾ�
			//���ο� ������� �ۼ��Ͽ���.
			//1���� 4�� ���� �Ҷ� �߰��� 2�� ���� ����� 2���� �ε�
			//2�� �Ѿ�� �ð��� �ּҽð��϶��� push�ϴ� ������ �ϴ�
			//�ٸ� �ߺ�üũ���� ������ �� �־���.
			//�Ƹ� �̰� �׸��� �˰����� �����κб��� �����ΰ����� �����.

			Q.push({ nx, t + 1 });
			if (nx == m) {
				if (cnt == 0) times = vis[nx]-1;
				cnt++;
			}
		}
	}
	cout << times << "\n" << cnt;

}