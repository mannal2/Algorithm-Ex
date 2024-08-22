#include <bits/stdc++.h>
using namespace std;

int n, m;
bool isUsed[11];
int arr[11];


void ffff(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (isUsed[i]) continue;
		arr[k] = i;
		isUsed[i] = 1;
		ffff(k + 1);
		isUsed[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	ffff(0);

}