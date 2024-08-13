#include <bits/stdc++.h>
using namespace std;

stack<char> ST;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s = "";
	bool co;
	while (1) {
		co = true;
		stack<char> ST;
		getline(cin, s);
		if (s == ".") break;
		for (char c : s) {
			if (c == '(' || c == '[') ST.push(c);
			else if (c == ')') {
				if (ST.empty() || ST.top()!='(') {
					co = false;
					break;
				}
				else ST.pop();
			}
			else if (c == ']') {
				if (ST.empty() || ST.top() != '[') {
					co = false;
					break;
				}
				else ST.pop();
			}
		}
		if (co&&ST.empty()) cout << "yes\n";
		else cout << "no\n";
	}

}