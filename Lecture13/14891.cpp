#include <bits/stdc++.h>
using namespace std;

int wheels[4][8];
int centerIndex[4];
int dx[] = { -1,1 };

void plusIndex(int index) {
	centerIndex[index-1]=(centerIndex[index-1] + 1) % 8;
}

void minusIndex(int index) {
	centerIndex[index - 1] = (centerIndex[index - 1] + 7) % 8;	
}

int getRightIndex(int index) { //N=0 S=1
	int tmp = (centerIndex[index - 1] + 2) % 8;
	return wheels[index - 1][tmp];
}

int getLeftIndex(int index) {
	int tmp = (centerIndex[index - 1] + 6) % 8;
	return wheels[index - 1][tmp];
}

void turnWheel(int index, int dir) {
	if (dir == 1) minusIndex(index);
	else plusIndex(index);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	
	for (int i = 0; i < 4; i++) {
		int a, b=7;
		cin >> a;
		while (a != 0) {
			wheels[i][b--] = a % 10;
			a = a / 10;
		}
	}
	
	int n;
	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		
		bool vis[5] = {};
		queue<pair<int,int>> Q;
		vector<pair<int, int>> V;
		// 현위치,  회전방향(-1,1)
		vis[a] = true;
		V.push_back({ a,b });
		Q.push({ a,b });
		while (!Q.empty()) {
			auto P = Q.front(); Q.pop();
			for (int i = 0; i < 2; i++) {
				int nx = P.first + dx[i];
				if (nx < 1 || nx >4) continue;
				if (vis[nx]) continue;
				if (i == 0) { //왼쪽
					if (getRightIndex(nx) != getLeftIndex(P.first)) {
						vis[nx] = true;
						V.push_back({ nx, P.second * -1 });
						Q.push({ nx, P.second * -1 });
					}
				}
				else {
					if (getRightIndex(P.first) != getLeftIndex(nx)) {
						vis[nx] = true;
						V.push_back({ nx, P.second * -1 });
						Q.push({ nx, P.second * -1 });
					}
				}
			}
		}
		for (auto P : V) {
			turnWheel(P.first, P.second);
		}
	}
	//for (int i = 0; i < 4; i++) cout << "centerIndex:" << centerIndex[i]<<"\n";
	int gob = 1;
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		if (wheels[i][centerIndex[i]] == 1) sum += gob;
		gob = gob * 2;
	}
	cout << sum;
}