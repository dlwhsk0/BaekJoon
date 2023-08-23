#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 배열을 그냥 입력된 대로 넣는게 아니라 축적된 시간을 넣는다
// 이분 탐색으로 빠르게 답을 찾기 (정확한 답이 아니라 최선값임에 주의)

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

    long long work, time; // 벌여놓은 일 개수, 알아볼 시간 개수
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