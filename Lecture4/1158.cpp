#include <bits/stdc++.h>
using namespace std;

int nxt[5001];
int pre[5001];
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		nxt[i] = (i == n) ? 1 : i + 1;
		pre[i] = (i == 1) ? n : i - 1;
	} //�������� �̿�

	int cnt = 1;
	int index = 1;
	while (v.size() != n) {
		if (cnt == k) {
			v.push_back(index);
			pre[nxt[index]] = pre[index];
			nxt[pre[index]] = nxt[index];
			cnt = 1; //�ε����� ���� �ε����� �̵��ǹǷ� cnt�� 1�� �ʱ�ȭ
		}
		else {
			cnt++;
		}
		index = nxt[index];
	}
	//��ºκ�
	cout << "<";
	for (int i = 0; i < n;i++) {
		cout << v[i];
		if (i != n - 1)cout << ", ";
	}
	cout << ">";
}