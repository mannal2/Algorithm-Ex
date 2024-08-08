#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a,n, ySum=0, mSum=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		ySum += (a / 30 + 1) * 10;
		mSum += (a / 60 + 1) * 15;
	}
	if (ySum < mSum) cout << "Y " << ySum;
	else if (ySum > mSum) cout << "M " << mSum;
	else cout << "Y M " << ySum;

}