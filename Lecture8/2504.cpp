#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num = 1, sum = 0;
	string s;
	stack<char> ST;
	bool plus = true;
	cin >> s;
	for (char c : s) {
		if (c == '(') {
			num *= 2;
			ST.push(c);
			plus = true;
		}
		else if (c == '[') {
			num *= 3;
			ST.push(c);
			plus=true;
		}
		else if (c == ')') {
			if (ST.empty() || ST.top() != '(') {
				cout << 0;
				return 0;
			}
			if(plus) sum += num;
			num /= 2;
			ST.pop();
			plus = false;
		}
		else if (c == ']') {
			if (ST.empty() || ST.top() != '[') {
				cout << 0;
				return 0;
			}
			if(plus) sum += num;
			num /= 3;
			ST.pop();
			plus = false;
		}
	}
	if (ST.empty())cout << sum;
	else cout << 0;
}

/*
// 괄호를 소거하고 숫자만 남기는 식으로 하려 했지만 실패
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	stack<char> ss;
	deque<int> ST;
	

	int cha;

	cin >> s;
	for (char c : s) {
		if (c == '(' || c == '[') ss.push(c);
		else {
			if (ss.top() == '(' && c == ')')ss.pop();
			else if (ss.top() == '[' && c == ']') ss.pop();
		}
		ST.push_back(c);
	}
	if (!ss.empty()) {
		cout << 0;
		return 0;
	}

	
	while (ST.size() != 1) {
		deque<int> CO;
		while (!ST.empty()) {
			if (ST.front() == '(' || ST.front() == '[') {
				cha = ST.front();
				CO.push_back(ST.front()); cout << (ST.front());
			}
			else if (ST.front() == ')' || ST.front() == ']') {
				if (CO.empty() || CO.back() == '(' && ST.front() == ')') {
					CO.pop_back();
					CO.push_back(2); cout << (ST.front());
				}
				else if (CO.empty() || CO.back() == '[' && ST.front() == ']') {
					CO.pop_back();
					CO.push_back(3); cout << (ST.front());
				}
				else if (cha == '(' && ST.front() == ')') {
					int n = CO.back();
					CO.pop_back();
					CO.pop_back();
					CO.push_back(n * 2); cout << (n*2);
				}
				else if (cha == '[' && ST.front() == ']') {
					int n = CO.back();
					CO.pop_back();
					CO.pop_back();
					CO.push_back(n * 3); cout << (n*3);
				}
			}
			else {
				if (CO.empty() || CO.back() != '(' || CO.back() != '[' || CO.back() != ']' || CO.back() != ')') {
					int n = CO.back();
					CO.pop_back();
					CO.push_back(n + ST.front()); cout << (ST.front());
				}
				else {
					CO.push_back(ST.front()); cout << (ST.front());
				}
			}
			ST.pop_front();
		}
		ST = CO;
	}
	cout << ST.front();

}*/