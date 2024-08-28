#include <bits/stdc++.h>
using namespace std;

int arr[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, w, l;
	int sec = 0;
	int cnt = 0;
	int index = 0;
	int weight = 0;
	queue<pair<int, int>> Q; //무게, 들어온시간
	cin >> n >> w >> l;
	
	for (int i = 0; i < n; i++) cin >> arr[i];

	while (1) {
		sec++;
		if (!Q.empty() && Q.front().second + w == sec) {
			weight -= Q.front().first;
			Q.pop();
		}
		if (weight + arr[index] <= l && arr[index]!=0) {
			Q.push({ arr[index], sec });
			weight += arr[index++];
		}
		if (Q.empty()) break;
	}
	cout << sec;
}