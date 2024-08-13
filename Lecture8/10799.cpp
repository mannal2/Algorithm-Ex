#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	int sum = 0;
	int left = 0;
	bool cutting;
	cin >> s;
	for (char c : s) {
		if (c == '(') {
			cutting = true;
			left++;
		}
		else {
			left--;
			if (cutting) {
				cutting = false;
				sum += left;
			}
			else sum++;
		}
	}
	cout << sum;

}