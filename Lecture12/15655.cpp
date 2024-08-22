#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[8];
int sss[8];

void ffff(int k) {
	if (k == m) {
		for (int i = 0; i < k; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++) {
		if (k == 0 || arr[k - 1] < sss[i]) {
			arr[k] = sss[i];
			ffff(k + 1);
		}

	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> sss[i];
	sort(sss, sss + n);
	ffff(0);

}