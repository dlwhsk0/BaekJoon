#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// �迭�� �׳� �Էµ� ��� �ִ°� �ƴ϶� ������ �ð��� �ִ´�
// �̺� Ž������ ������ ���� ã�� (��Ȯ�� ���� �ƴ϶� �ּ����ӿ� ����)

vector<long long> v;
int n, m;

int binary(long long t, int start, int end) {
    if (start > end) { return start; }

    int mid = (start + end) / 2;

    if (v[mid] > t) { return binary(t, start, mid - 1); }
    else { return binary(t, mid + 1, end); }

    return start;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long work, time; // �������� �� ����, �˾ƺ� �ð� ����
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> work;
        if (i != 0) { work += v[i - 1]; }
        v.push_back(work);
    }

    for (int i = 0; i < m; i++) {
        cin >> time;
        cout << binary(time, 0, n - 1) << '\n';
    }

    return 0;
}