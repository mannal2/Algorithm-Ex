#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;
	int min = b <= c ? b : c;
	int max = b > c ? b : c;

	int mid;
	if (a <= min) {
		mid = min;
		min = a;
	}
	else if (a > max) {
		mid = max;
		max = a;
	}
	else {
		mid = a;
	}

	cout << min << " " << mid << " " << max;


}