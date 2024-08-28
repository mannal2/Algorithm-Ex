#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

int getDist(pair<int, int> A, pair<int, int> B) {
	return abs(A.first - B.first) + abs(A.second - B.second);
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int a;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a;
			if (a == 1) house.push_back({ i, j });
			else if (a == 2) chicken.push_back({ i, j });
		}
	}
	vector<int> vvv;
	for (int i = 0; i < chicken.size(); i++) vvv.push_back(i < m ? 0 : 1);
	int minNum = 100000;

	do {
		int tmpSum = 0;
		for (auto home : house) { //각 가정집
			int tmpMin = 10000;
			for (int i = 0; i < vvv.size(); i++) {
				if (vvv[i] == 0) { //각 치킨집
					tmpMin = min(tmpMin, getDist(home, chicken[i]));
				}
			}
			tmpSum += tmpMin;
		}
		minNum = min(minNum, tmpSum);
		
	} while (next_permutation(vvv.begin(), vvv.end()));
	cout << minNum;
}