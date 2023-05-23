#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
* n���� ���� ����ī�� / �� ����ī��
* �� ����ī�� �� k���� �������� ����ī�� (�� �� ����)
* �������� �� �� ������ �� ��
* �� ������ ���� ����, ��� ������ ������ ���
* 
* >>�ּ��� ������� ����<<
* ���ͷ� ���� �ְ� �ִ밪 ã��
* �ִ밪�� ����� �� ����ī�� �����ϱ�
*/

int share[101];
int team[101];
int temp, maxnum;
int n, k, tidx;

void card() {
	maxnum = -100000000;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (team[j] == 10000) {	continue; }

			temp = share[i] * team[j];

			if (maxnum < temp) {
				maxnum = temp;
				tidx = j; // �ִ�� ����� �� ����ī�� �ε���
			}
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> n >> k;
	for (int i = 0; i < n; i++) { cin >> share[i]; }
	for (int i = 0; i < n; i++) { cin >> team[i]; }

	for(int i = 0; i <= k; i++) { // ����
		card();
		team[tidx] = 10000; // ������ ī�� �� ����
	}
	cout << maxnum;

	return 0;
}