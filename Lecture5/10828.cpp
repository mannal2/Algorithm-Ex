#include <bits/stdc++.h>
using namespace std;

int st[10001];
int pos = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string s;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin.ignore();
		cin >> s;
		if (s.compare("push")==0) {
			int x;
			cin >> x;
			st[pos++] = x;
		}
		else if (s.compare("pop")==0) {
			if (!pos) cout << "-1\n";
			else cout << st[--pos] << "\n";
		}
		else if (s.compare("size")==0) {
			cout << pos << "\n";
		}
		else if (s.compare("empty")==0) {
			if (!pos) cout << "1\n";
			else cout << "0\n";
		}
		else if (s.compare("top")==0) {
			if (!pos)cout << "-1\n";
			else cout << st[pos - 1]<<"\n";
		}
	}

}