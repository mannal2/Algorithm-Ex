#include <bits/stdc++.h>
using namespace std;

deque<int> DQ;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int max, n;
	cin >> max >> n;
	
	for (int i = 1; i <= max; i++) {
		DQ.push_back(i);
	}
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		int t = find(DQ.begin(), DQ.end(), x)-DQ.begin(); //덱은 원소의 위치를 찾을 수 있다.
		int right = DQ.size() - t;
		if (t <= right) {
			cnt += t;
			while (t--) {
				DQ.push_back(DQ.front());
				DQ.pop_front();
			}
		}
		else {
			cnt += right;
			while (right--) {
				DQ.push_front(DQ.back());
				DQ.pop_back();
			}
		}
		DQ.pop_front();
	}
	cout << cnt;

}