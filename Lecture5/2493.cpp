/*
#include <bits/stdc++.h>
using namespace std;

int n;
stack<int> st, copys;
stack<int> topNum;

 //시간초과
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		st.push(x);
	}
	for (int i = 1; i <= n; i++) {
		int num = st.top();
		int cnt = n - i;
		st.pop();
	
		while (!st.empty() && st.top() < num) {
			if (st.empty()) {
				cnt = 0;
				break;
			}
			copys.push(st.top());
			st.pop();
			cnt--;
		}
		topNum.push(cnt);
		while (!copys.empty()) {
			st.push(copys.top());
			copys.pop();
		}
	}
	while (!topNum.empty()) {
		cout << topNum.top() << " ";
		topNum.pop();
	}
}*/

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N;
stack<pair<int, int>> tower;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	tower.push({ 100000001, 0 });
	for (int i = 1; i <= N; i++) { //tower에는 결국 (100000001,0) (9,2) (7.4) 이렇게 내림차순으로만 남겨짐
		int height;                //각 간격을 더 좁게 하는 수가 나오면 변경됨. 예) 9 7 <- 8이 들어가면 9 8
		cin >> height;
		while (tower.top().X < height)
			tower.pop();
		cout << tower.top().Y << " ";
		tower.push({ height, i });
	}
}