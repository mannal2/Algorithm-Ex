#include <bits/stdc++.h>
using namespace std;

int DQ[10001];
int head = 5000, tail = 5000;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "push_front") {
			int x;
			cin >> x;
			DQ[--head] = x;
		}
		else if (s == "push_back") {
			int x;
			cin >> x;
			DQ[tail++] = x;
		}
		else if (s == "pop_front") {
			if (tail ==head) cout << "-1\n";
			else {
				cout << DQ[head++] << "\n";
			}
		}
		else if (s == "pop_back") {
			if (tail == head) cout << "-1\n";
			else {
				cout << DQ[--tail] << "\n";
			}
		}
		else if (s == "size") {
			cout << tail - head << "\n";
		}
		else if (s == "empty") {
			if (tail - head == 0)cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (s == "front") {
			if (tail - head == 0) cout << -1 << "\n";
			else {
				cout << DQ[head] << "\n";
			}
		}
		else if (s == "back") {
			if (tail - head == 0) cout << -1 << "\n";
			else {
				cout << DQ[tail - 1] << "\n";
			}
		}
	}

}