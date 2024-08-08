#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int max = 0;
	int n, index;
	for (int i = 1; i <= 9; i++) {
		cin >> n;
		if (n > max) {
			max = n;
			index = i;
		}
	}
	cout << max << "\n" << index;
}