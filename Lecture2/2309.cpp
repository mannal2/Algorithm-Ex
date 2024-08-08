#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n[9], cha, sum = 0, flag=0;
	for (int i = 0; i < 9; i++) {
		cin >> n[i];
		sum += n[i];
	}
	vector <int>v(n, n + 9);
	sort(v.begin(), v.end());
	cha = sum - 100;
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (n[i] + n[j] == cha) {
				remove(v.begin(), v.end(), n[i]);
				remove(v.begin(), v.end(), n[j]);
				flag = 1;
				break;
			}
		}
		if (flag)break;
	}
	for (int i = 0; i < 7; i++) cout << v[i] << "\n";
}