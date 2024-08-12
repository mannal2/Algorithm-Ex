#include <bits/stdc++.h>
using namespace std;

int Q[10001];
int head=0, tail=0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "push") {
			int x;
			cin >> x;
			Q[tail++]=x;
		}
		else if (s == "pop") {
			if (tail - head == 0) cout << "-1\n";
			else {
				cout << Q[head++]<<"\n";
			}
		}
		else if (s == "size") {
			cout << tail - head << "\n";
		}
		else if (s == "empty"){
			if (tail - head == 0)cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (s == "front") {
			if (tail - head == 0) cout << -1 << "\n";
			else {
				cout << Q[head] << "\n";
			}
		}
		else if(s == "back"){
			if (tail - head == 0) cout << -1 << "\n";
			else {
				cout << Q[tail-1] << "\n";
			}
		}
	}

}