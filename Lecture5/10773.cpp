#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, sum=0;
	stack<int> s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 0) {
			if (!s.empty()) s.pop();
		}
		else {
			s.push(x);
		}
	}
	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}
	cout << sum;
}