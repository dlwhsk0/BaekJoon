#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// LIS ���� : ���� ���� �κ� ����

int arr[2001];
vector<int> v;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, num, i, maxnum = 0;
    cin >> n;

    for (i = 0; i < n; i++) { // �Է� �ޱ�
        cin >> num;
        v.push_back(num);
    }
    reverse(v.begin(), v.end()); // ����� �������� ���ϴ� �������� �ٲٱ�

    for (i = 0; i < n; i++) { // LIS
        arr[i] = 1;
        for (int j = 0; j < i; j++) {
            if (v[j] < v[i]) {
                arr[i] = max(arr[i], arr[j] + 1); // �� ������Ʈ
            }
        }
    }

    for (i = 0; i < n; i++) { // �ִ�
        maxnum = max(maxnum, arr[i]);
    }
    cout << n - maxnum;

    return 0;
}