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
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		if (isUsed[i] || tmp == sss[i]) continue; //마지막 수열 숫자가 그전 수열의 마지막과 같으면 중복
		if (k != 0 && arr[k - 1] > sss[i]) continue;
		isUsed[i] = 1;
		tmp = sss[i];
		arr[k] = sss[i];
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