#include <bits/stdc++.h>
using namespace std;

int n;

void ffff(int k) {
	for (int i = 0; i < k; i++) cout << "____";
	cout << "\"����Լ��� ������?\"\n";
	if (k == n) {
		for (int i = 0; i < k; i++) cout << "____";
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
	}
	else {
		for (int i = 0; i < k; i++) cout << "____";
		cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
		for (int i = 0; i < k; i++) cout << "____"; 
		cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
		for (int i = 0; i < k; i++) cout << "____";
		cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
		ffff(k + 1);
	}
	for (int i = 0; i < k; i++) cout << "____";
	cout << "��� �亯�Ͽ���.\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	ffff(0);
}