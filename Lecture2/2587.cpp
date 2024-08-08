#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n[5], sum = 0;
	for (int i = 0; i < 5; i++) {
		cin >> n[i];
		sum += n[i];
	}

	sort(n, n + 5);
	cout << sum / 5 << "\n";
	cout << n[2];

}