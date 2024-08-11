#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	list<char> L;
	string s;
	int n;
	char c;
	cin >> s;

	for (auto a : s) L.push_back(a);
	list<char>::iterator t = L.end();
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++) {
		cin >> c;
		if (c == 'L') {
			if (t != L.begin()) t--;
		}
		else if (c == 'D') {
			if (t != L.end()) t++;
		}
		else if (c == 'B') {
			if (t != L.begin()) {
				t--;
				t = L.erase(t);
			}
		}
		else if (c == 'P') {
			cin >> c;
			L.insert(t, c);

		}
	}

	for (auto i : L) cout << i;
}