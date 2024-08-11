#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	
	string s;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;
		list<char> L;
		list<char>::iterator t = L.end();
		for (auto a : s) {
			if (a == '<') {
				if (t != L.begin()) t--;
			}
			else if (a == '>') {
				if (t != L.end())t++;
			}
			else if (a == '-'){
				if (t != L.begin()) {
					t--;
					t = L.erase(t);
				}
			}
			else {
				L.insert(t, a);
				
			}
		}

		for (auto i : L) cout << i;
		cout << "\n";
	}
}