#include <bits/stdc++.h>
using namespace std;

int n, l;
int board[102][102];
int roro[102][102];
int roro2[102][102];

bool pass[2][102]; // ���� ����

void garoCheck() {
	for (int i = 0; i < n; i++) {
		int first = board[i][0];
		int cnt = 1;
		for (int j = 1; j < n; j++) {
			if (first == board[i][j]) {
				cnt++;
				//cout << "��ĭ�� ���� ";
			}
			else {
				if (first + 1 == board[i][j]) { //���θ� �������ִ��� üũ
					if (cnt < l) { //���θ� ���� ������ ����
						//cout << "���� ���� ���� ";
						pass[0][i] = true;
						break;
					}
					else { //���θ� ���� ������ ������
						int tmp = 0;
						for (int k = j - l; k < j; k++) {
							if (roro[i][k] == 0) tmp++;
						}
						if (tmp == l) {
							for (int k = j - l; k < j; k++) {
								roro[i][k] = 1;
							}
							first = board[i][j];
							cnt = 1;
							//cout << "���� ��ġ ";
						}
						else { //���� �ߺ�
							//cout << "���� �ߺ� ";
							pass[0][i] = true;
							break;
						}
					}
				}
				else if(first + 1 < board[i][j]) { //���θ� ���� �� ������, 2�̻� ū��
					//cout << "���� �������� �ȵ� ";
					pass[0][i] = true;
					break;
				}
				else {
					first = board[i][j];
					cnt = 1;
					//cout << "���̰� �������� �κ� ";
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		int first = board[i][n-1];
		int cnt = 1;
		if (pass[0][i]) {
			//cout << "�н���\n";
			continue;
		}
		for (int j = n-2; j >= 0; j--) {
			if (first == board[i][j]) {
				cnt++;
				//cout << "��ĭ�� ���� ";
			}
			else {
				if (first + 1 == board[i][j]) { //���θ� �������ִ��� üũ
					if (cnt < l) { //���θ� ���� ������ ����
						//cout << "���� ���� ���� ";
						pass[0][i] = true;
						break;
					}
					else { //���θ� ���� ������ ������
						int tmp = 0;
						for (int k = j + l; k > j; k--) {
							if (roro[i][k] == 0) tmp++;
						}
						if (tmp == l) {
							for (int k = j + l; k > j; k--) {
								roro[i][k] = 1;
							}
							first = board[i][j];
							cnt = 1;
							//cout << "���� ��ġ ";
						}
						else { //���� �ߺ�
							//cout << "���� �ߺ� ";
							pass[0][i] = true;
							break;
						}
					}
				}
				else if (first + 1 < board[i][j]) { //���θ� ���� �� ������, 2�̻� ū��
					//cout << "���� �������� �ȵ� ";
					pass[0][i] = true;
					break;
				}
				else {
					//cout << "���̰� �������� �κ� ";
					first = board[i][j];
					cnt = 1;
				}
			}
		}
	}
}

void seroCheck() {
	for (int j = 0; j < n; j++) {
		int first = board[0][j];
		int cnt = 1;
		for (int i = 1; i < n; i++) {
			if (first == board[i][j]) {
				cnt++;
				//cout << "��ĭ�� ���� ";
			}
			else {
				if (first + 1 == board[i][j]) { //���θ� �������ִ��� üũ
					if (cnt < l) { //���θ� ���� ������ ����
						//cout << "���� ���� ���� ";
						pass[1][j] = true;
						break;
					}
					else { //���θ� ���� ������ ������
						int tmp = 0;
						for (int k = i - l; k < i; k++) {
							if (roro2[k][j] == 0) tmp++;
						}
						if (tmp == l) {
							for (int k = i - l; k < i; k++) {
								roro2[k][j] = 1;
							}
							first = board[i][j];
							cnt = 1;
							//cout << "���� ��ġ ";
						}
						else { //���� �ߺ�
							//cout << "���� �ߺ� ";
							pass[1][j] = true;
							break;
						}
					}
				}
				else if (first + 1 < board[i][j]) { //���θ� ���� �� ������, 2�̻� ū��
					//cout << "���� �������� �ȵ� ";
					pass[1][j] = true;
					break;
				}
				else {
					//cout << "���̰� �������� �κ� ";
					first = board[i][j];
					cnt = 1;
				}
			}
		}
	}
	for (int j = 0; j < n; j++) {
		int first = board[n-1][j];
		int cnt = 1;
		if (pass[1][j]) {
			//cout << "�н���\n";
			continue;
		}
		for (int i = n-2; i >=0; i--) {
			if (first == board[i][j]) {
				cnt++;
				//cout << "��ĭ�� ���� ";
			}
			else {
				if (first + 1 == board[i][j]) { //���θ� �������ִ��� üũ
					if (cnt < l) { //���θ� ���� ������ ����
						//cout << "���� ���� ���� ";
						pass[1][j] = true;
						break;
					}
					else { //���θ� ���� ������ ������
						int tmp = 0;
						for (int k = i + l; k > i; k--) {
							if (roro2[k][j] == 0) tmp++;
						}
						if (tmp == l) {
							for (int k = i + l; k > i; k--) {
								roro2[k][j] = 1;
							}
							first = board[i][j];
							cnt = 1;
							//cout << "���� ��ġ ";
						}
						else { //���� �ߺ�
							//cout << "���� �ߺ� ";
							pass[1][j] = true;
							break;
						}
					}
				}
				else if (first + 1 < board[i][j]) { //���θ� ���� �� ������, 2�̻� ū��
					//cout << "���� �������� �ȵ� ";
					pass[1][j] = true;
					break;
				}
				else {
					//cout << "���̰� �������� �κ� ";
					first = board[i][j];
					cnt = 1;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	garoCheck();
	seroCheck();

	int sum = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			if (!pass[i][j]) sum++;
		}
	}
	cout << sum;
}