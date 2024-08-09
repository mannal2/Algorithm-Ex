#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	vector<int> v(26);
	cin >> s;
	
	for (int i = 0; i < s.length(); i++) {
		v[(int)s[i]-97]++;
	}
	for (int i : v) cout << i <<" ";

}