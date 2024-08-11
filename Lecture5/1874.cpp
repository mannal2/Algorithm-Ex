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
		if (st.empty() || curX> st.top()) { //���ÿ� �߰�
			st.push(len++);
			v.push_back('+');
		}
		else { //���ÿ��� ����
			if (curX == st.top()) { //�Է°��� ������
				cnt++;
				st.pop();
				v.push_back('-');
				input = true;
			}
			else { //�ٸ��� ������ �ϼ��� �� ��� break
				break;
			}
		}
		if (st.empty() && cnt == n) break; //������ �ϼ��Ǹ� break
	}
	if (cnt != n) cout << "NO";
	else {
		for (char c : v) cout << c << "\n";
	}

}