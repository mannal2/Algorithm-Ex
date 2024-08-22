#include <bits/stdc++.h>
using namespace std;

int n;
int arr[15];
int sss[15];

void ffff(int k) {
	if (k == 6) {
		for (int i = 0; i < k; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		if (k != 0 && arr[k - 1] >= sss[i]) continue;
		arr[k] = sss[i];
		ffff(k + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) cin >> sss[i];
		ffff(0);
		cout << "\n";
	}

}