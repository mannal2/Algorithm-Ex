#include <bits/stdc++.h>
using namespace std;

int board[22][22];
int n;
int minNum = 1000000;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int end= tgamma(n + 1)/tgamma(n/2+1)/tgamma(n/2+1)/2;
	
	int cnt = 0;
	
	vector<int> V;
	for (int i = 0; i < n; i++)V.push_back(i < n / 2 ? 0 : 1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	do {
		vector<int> P1, P2;
		for (int i = 0; i < V.size(); i++) {
			if (V[i] == 0) P1.push_back(i);
			else P2.push_back(i);
		}

		int sum1 = 0, sum2 = 0;
		for (int i = 0; i < P1.size(); i++) {
			for (int j = 0; j < P1.size(); j++) {
				if (i == j) continue;
				sum1 += board[P1[i]][P1[j]];
			}
		}
		for (int i = 0; i < P2.size(); i++) {
			for (int j = 0; j < P2.size(); j++) {
				if (i == j) continue;
				sum2 += board[P2[i]][P2[j]];
			}
		}
		minNum = min(minNum, abs(sum1 - sum2));
		//cnt++;
		//if (cnt == end) break;

	} while (next_permutation(V.begin(), V.end()));
	cout << minNum;
}