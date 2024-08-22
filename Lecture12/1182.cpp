#include <bits/stdc++.h>
using namespace std;

int n, ans, cnt;
int arr[20];
int isUsed[20];

void ffff(int k, int sum) {
    /*
    for (int i = 0; i < n; i++) {
        if (isUsed[i]) cout << i << " ";
    }
    cout << "\n";*/
    if (sum == ans && k != 0) {
        cnt++;
    }
    if (k == n) return;
    for (int i = k; i < n; i++) { // i¸¦ k·Î ¹Ù²ãÁÜ
        if (isUsed[i]) continue;
        isUsed[i] = 1;
        ffff(i + 1, sum + arr[i]);
        isUsed[i] = 0;
    }
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> ans;
	for (int i = 0; i < n; i++) cin >> arr[i];
	ffff(0, 0);
	cout << cnt;
}