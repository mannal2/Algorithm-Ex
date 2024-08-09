#include <bits/stdc++.h>
using namespace std;
//용량이 큰 변수 사용시 전역변수 사용
int v[1000001] = {};
vector<int> v2;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,a,x, cnt=0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a;
		v[a] = 1; //각 숫자를 인덱스로 하는 배열칸을 1로 설정
		v2.push_back(a); //입력된 숫자들의 배열
	}
	cin >> x;
	for (int f : v2) {
		if (x < f || x-f > 1000001) continue;
		if (v[x-f]) cnt++;
	}
	cout << cnt/2;
}

/* //벡터를 사용하지 않는 알고리즘
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