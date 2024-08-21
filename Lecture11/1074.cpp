#include <bits/stdc++.h>
using namespace std;

int func(int n, int r, int c) {
	if (n == 1) return 2 * r + c;
	else {
		int tn = pow(2, n - 1);
		int tr = r / tn;
		int tc = c / tn;
		return (2 * tr + tc) * pow(2, 2 * n - 2) + func(n - 1, r%tn, c%tn);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, r, c;
	cin >> n >> r >> c;
	cout << func(n, r, c);

}