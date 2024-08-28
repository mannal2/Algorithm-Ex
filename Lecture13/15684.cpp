#include <bits/stdc++.h>
using namespace std;

int board[32][12];
int tmp[32][12];
int n, m, h;
int cnt;
vector<int> V;
vector<int> arr;

bool checkSadari() {
	for (int j = 1; j <= n; j++) {
		int index = j;
		int start = 0;
		while (start != h + 1) {
			start++;
			if (board[start][index] != 0) index+=board[start][index];
		}
		if (j != index) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> h;
	while (m--) {
		int a, b;
		cin >> a >> b;
		tmp[a][b] = 1;
		tmp[a][b + 1] = -1;
	}
	
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			if (tmp[i][j] == 0 && tmp[i][j + 1] == 0) {
				V.push_back(i * n + j);
			}
		}
	}

	for (int i = 0; i < V.size(); i++) arr.push_back(1);
	while (1) {
		do {
			copy(&tmp[0][0], &tmp[0][0] + 384, &board[0][0]);
			for (int i = 0; i < arr.size(); i++) {
				if (arr[i] == 0) {
					board[V[i] / n][V[i] % n] = 1;
					board[V[i] / n][V[i] % n + 1] = -1;
				}
			}
			if (checkSadari()) {
				if (cnt <= 3)
					cout << cnt;
				else
					cout << -1;
				return 0;
			}
		} while (next_permutation(arr.begin(), arr.end()));
		cnt++;
		if (cnt > 3) {
			cout << -1;
			return 0;
		}
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] == 1) {
				arr[i] = 0;
				break;
			}
		}
	}

}