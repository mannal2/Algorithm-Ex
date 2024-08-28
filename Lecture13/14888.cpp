#include <bits/stdc++.h>
using namespace std;

vector<int> V;
vector<int> V2;

int minNumber = 1000000000;
int maxNumber = -1000000000;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--) {
		int a;
		cin >> a;
		V.push_back(a);
	}
	for(int i=0;i<4;i++){
		int a;
		cin >> a;
		while (a--) V2.push_back(i);
	}
	do {
		vector<int> cc;
		for (int i = 0; i < V2.size(); i++) cc.push_back(V2[i]);
		int sum = V[0];
		for (int i = 1; i < V.size(); i++) {
			if (cc[i - 1] == 0) {
				sum = sum + V[i];
			}
			else if (cc[i - 1] == 1) {
				sum = sum - V[i];
			}
			else if (cc[i - 1] == 2) {
				sum = sum * V[i];
			}
			else {
				sum = sum / V[i];
			}
		}
		maxNumber = max(maxNumber, sum);
		minNumber = min(minNumber, sum);

	} while (next_permutation(V2.begin(), V2.end()));
	cout << maxNumber << "\n" << minNumber;
}