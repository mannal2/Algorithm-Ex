#include <bits/stdc++.h>
using namespace std;

int board[22][22];
int tmp[22][22];
int maxNumber = 0;
int n;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 }; //0 1 2 3 상하좌우

void moveBoard(int dir) {
	bool change[22][22] = {};
	if (dir == 0) {
		for (int i = 1; i < n; i++) { //여기 수정
			for (int j = 0; j < n; j++) {
				if (board[i][j] != 0) {
					int nx = i;
					while (nx - 1 > 0 && board[nx - 1][j] == 0) nx--;
					if (board[nx - 1][j] == 0) {
						board[nx - 1][j] = board[i][j];
						board[i][j] = 0;
					}
					else if (board[nx - 1][j] == board[i][j] && !change[nx-1][j]) {
						change[nx - 1][j] = true;
						board[nx - 1][j] *= 2;
						maxNumber = max(maxNumber, board[nx - 1][j]);
						board[i][j] = 0;
					}
					else if(nx!=i){
						board[nx][j] = board[i][j];
						board[i][j] = 0;
					}
				}
			}
		}
	}
	else if (dir == 1) {
		for (int i = n - 2; i >= 0; i--) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] != 0) {
					int nx = i;
					while (nx + 1 < n-1 && board[nx + 1][j] == 0) nx++;
					if (board[nx + 1][j] == 0) {
						board[nx + 1][j] = board[i][j];
						board[i][j] = 0;
					}
					else if (board[nx + 1][j] == board[i][j] && !change[nx+1][j]) {
						change[nx + 1][j] = true;
						board[nx + 1][j] *= 2;
						maxNumber = max(maxNumber, board[nx + 1][j]);
						board[i][j] = 0;
					}
					else if(nx!=i){
						board[nx][j] = board[i][j];
						board[i][j] = 0;
					}
				}
			}
		}
	}
	else if (dir == 2) { //좌
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[j][i] != 0) {
					int ny = i;
					while (ny - 1 > 0 && board[j][ny-1] == 0) ny--;
					if (board[j][ny-1] == 0) {
						board[j][ny-1] = board[j][i];
						board[j][i] = 0;
					}
					else if (board[j][ny-1] == board[j][i] && !change[j][ny-1]) {
						change[j][ny - 1] = true;
						board[j][ny-1] *= 2;
						maxNumber = max(maxNumber, board[j][ny-1]);
						board[j][i] = 0;
					}
					else if (ny != i) {
						board[j][ny] = board[j][i];
						board[j][i] = 0;
					}
				}
			}
		}
	}
	else if (dir == 3) { //우
		for (int i = n-2; i >= 0; i--) {
			for (int j = 0; j < n; j++) {
				if (board[j][i] != 0) {
					int ny = i;
					while (ny + 1 < n-1 && board[j][ny + 1] == 0) ny++;
					if (board[j][ny + 1] == 0) {
						board[j][ny + 1] = board[j][i];
						board[j][i] = 0;
					}
					else if (board[j][ny + 1] == board[j][i] && !change[j][ny+1]) {
						change[j][ny + 1] = true;
						board[j][ny + 1] *= 2;
						maxNumber = max(maxNumber, board[j][ny+1]);
						board[j][i] = 0;
					}
					else if (ny != i) {
						board[j][ny] = board[j][i];
						board[j][i] = 0;
					}
				}
			}
		}
	}
}

void ffff() {
	for (int a = 0; a < 4; a++) {
		for (int b = 0; b < 4; b++) {
			for (int c = 0; c < 4; c++) {
				for (int d = 0; d < 4; d++) {
					for (int e = 0; e < 4; e++) {
						copy(&tmp[0][0], &tmp[0][0] + 484, &board[0][0]);
						moveBoard(a);
						moveBoard(b);
						moveBoard(c);
						moveBoard(d);
						moveBoard(e);
					}
				}
			}
		}
	}
}

void printBoard() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> tmp[i][j];
			maxNumber = max(maxNumber, tmp[i][j]);
		}
	}
	
	copy(&tmp[0][0], &tmp[0][0] + 484, &board[0][0]);
	/*
	int inn=0;
	while (inn != -1) {
		cin >> inn;
		cout << "\n";
		moveBoard(inn);
		printBoard();
		cout << "\n";
	}*/
	ffff();
	cout << maxNumber;
}