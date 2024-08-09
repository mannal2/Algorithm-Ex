#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c;
	vector<int> v(10);
	cin >> a >> b >> c;
	int n = a * b * c;

	string abcd = to_string(n);

	for (auto a : abcd) {
		v[a-'0']++;
	}
	for (auto a : v) cout << a << "\n";

}