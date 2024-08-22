#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[8];

void ffff(int k) {
	if (k == m) {
		for (int i = 0; i < k; i++) {
			cout << arr[i] + 1 << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++) {
		arr[k] = i;
		ffff(k + 1);
	}
}

void ffff2() {
	vector<int> V;
	for (int i = 0; i < n; i++) {
		if (i < m)V.push_back(0);
		else V.push_back(1);
	}

	do {
		for (int i = 0; i < n; i++) {
			if (V[i] == 0) cout << i + 1 << " ";
		}
		cout << "\n";
	} while (next_permutation(V.begin(), V.end()));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	ffff(0);

	
}