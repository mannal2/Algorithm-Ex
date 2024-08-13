#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	int n, cnt=0;
	cin >> n;
	cin.ignore(); //숫자뒤 getline을 하려면 추가
	while (n--) {
		getline(cin, s);
		stack<char> ST;
		for (char c : s) {
			if (ST.empty()) ST.push(c);
			else {
				if (ST.top() == c) ST.pop();
				else ST.push(c);
			}
		}
		if (ST.empty())cnt++;
	}
	cout << cnt;

}