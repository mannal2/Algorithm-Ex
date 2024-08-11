#include <bits/stdc++.h>
using namespace std;

stack<int> st;
vector<char> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, len=1, cnt=0;
	int curX;
	bool input = true;
	cin >> n;
	while (1) {
		if (input) {
			cin >> curX;
			input = false;
		}
		if (st.empty() || curX> st.top()) { //스택에 추가
			st.push(len++);
			v.push_back('+');
		}
		else { //스택에서 빼기
			if (curX == st.top()) { //입력값과 같을때
				cnt++;
				st.pop();
				v.push_back('-');
				input = true;
			}
			else { //다르면 수열을 완성할 수 없어서 break
				break;
			}
		}
		if (st.empty() && cnt == n) break; //수열이 완성되면 break
	}
	if (cnt != n) cout << "NO";
	else {
		for (char c : v) cout << c << "\n";
	}

}