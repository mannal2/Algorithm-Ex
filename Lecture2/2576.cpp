#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, max = 1e20, sum=0;
	for (int i = 0; i < 7; i++) {
		cin >> n;
		if (n % 2 == 1) {
			if (n < max) max = n;
			sum += n;
		}
	}
	if (sum != 0)
		cout << sum << "\n" << max;
	else
		cout << "-1";
}