#include <bits/stdc++.h>
using namespace std;
//�뷮�� ū ���� ���� �������� ���
int v[1000001] = {};
vector<int> v2;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,a,x, cnt=0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a;
		v[a] = 1; //�� ���ڸ� �ε����� �ϴ� �迭ĭ�� 1�� ����
		v2.push_back(a); //�Էµ� ���ڵ��� �迭
	}
	cin >> x;
	for (int f : v2) {
		if (x < f || x-f > 1000001) continue;
		if (v[x-f]) cnt++;
	}
	cout << cnt/2;
}

/* //���͸� ������� �ʴ� �˰���
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int v[1000001] = {};
	bool occur[2000001] = {};

	int n, x, cnt = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cin >> x;

	for (int i = 0; i < n; i++) {
		if (x - v[i] > 0 && occur[x - v[i]])cnt++;
		occur[v[i]] = true;
	}
	cout << cnt;
}*/