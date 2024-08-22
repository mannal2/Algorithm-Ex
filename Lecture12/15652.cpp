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
		if (k == 0 || arr[k - 1] <= i) {
			arr[k] = i;
			ffff(k + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	ffff(0);


}