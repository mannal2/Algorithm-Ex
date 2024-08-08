#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a[6] = { 0,0,0,0,0,0 };
	int n, max=0;
	for (int i = 0; i < 3; i++) {
		cin >> n;
		a[n - 1]++;
	}
	for (int i = 5; i >= 0; i--) {
		if (a[i] == 3) {
			cout << 10000 + (i + 1) * 1000;
			return 0;
		}
		else if (a[i] == 2) {
			cout << 1000 + (i + 1) * 100;
			return 0;
		}
		if (a[i] == 1) {
			if ((i + 1) > max)max = i + 1;
		}
	}
	cout << max * 100;
	
}