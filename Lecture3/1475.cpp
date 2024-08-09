#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int a[9] = {};
	while (n > 0) {
		if (n % 10 == 9) a[6]++; //9일때 6칸 값을 +1
		else a[n % 10]++;
		n /= 10;
	}
	a[6] = (a[6] + 1) / 2; //6칸은 9도 포함하므로 /2
	int max = 0;
	for (auto num : a) {
		if (num > max)max = num;
	}
	cout << max;

}