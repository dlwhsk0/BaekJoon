#include <iostream>
#include <algorithm>
#include <cmath> // log2(), pow()
using namespace std;

// 1. �Է¹޴� ���� ��� log2 ó�� �ؼ� �����鸸 ���� �迭�� �����Ѵ�.
// 2. �տ������� 2�� ���� ¦�� �Ǵ� �� ��ŭ ���� ������ ���� �����ش�.
// 3. �ڿ������� �˻��� ���� ū ���� ã�Ƴ� ������ ������ ���� ���� ���� ���Ѵ�.

int arr[63]; // 2�� 0~62 ������ ����

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    long long l; // ~2^62�� long long
    cin >> n;

    for (int i = 0; i < n; i++) { // �Է�
        cin >> l;
        if (l != 0) { // log2 ó���� ������ �̾Ƴ� ������ 1 �����Ѵ�.
            l = log2(l);
            arr[l]++;
        }
    }

    for (int i = 0; i < 62; i++) {
        arr[i + 1] += arr[i] / 2;
    }

    for (int i = 62; i >= 0; i--) {
        if (arr[i] != 0) {
            cout << (long long)pow(2, i); // 2^i ���
            // !!!!!! pow�� �Ǽ����� �����ϴµ�
            // �Ǽ����� ��û ū ���� ǥ�� �� ��
            // 2345e+18 �̷� ������ �ڸ� �߶����.
            // �׷��� Ʋ�ȴ� ����! ��������ȯ ���ָ� ����!!
            return 0;
        }
    }

    return 0;
}