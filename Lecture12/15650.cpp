#include <bits/stdc++.h>
using namespace std;

int n, m;
int isUsed[8];
int arr[8];

void ffff(int k) {
	if (k == m) {
		for (int i = 0; i < k; i++) {
			cout << arr[i]+1 << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++) {
		if (isUsed[i]) continue;
		if (k == 0 || arr[k - 1] < i) {
			arr[k] = i;
			isUsed[i] = 1;
			ffff(k + 1);
			isUsed[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	//ffff(0);

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