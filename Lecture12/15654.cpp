#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[8];
int sss[8];
bool isUsed[8];

void ffff(int k) {
	if (k == m) {
		for (int i = 0; i < k; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++) {
		if (isUsed[i]) continue;
		arr[k] = sss[i];
		isUsed[i] = 1;
		ffff(k + 1);
		isUsed[i] = 0;
		
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