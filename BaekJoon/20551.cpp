#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// 이분탐색으로 찾고 찾아내면 가장 먼저인 위치를 찾아야함
// 없을 때까지 이분 탐색

vector<long long> v;

int binary_search(long long num, int start, int end) {
    int mid = (start + end) / 2;
    if (start > end) { return -1; }

    if (v[mid] == num) { // 찾으면 더 없을 때까지 이분 탐색
        int temp = mid;
        while (true) {
            temp = binary_search(num, 0, temp - 1);
            if (temp == -1) { break; } // 존재하지 않으면 끝
            else { mid = temp; }
        }
        return mid;
    }
    else if (v[mid] < num) { return binary_search(num, mid + 1, end); }
    else { return binary_search(num, start, mid - 1); }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, idx;
    long long num;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < m; i++) {
        cin >> num;
        idx = binary_search(num, 0, n - 1);
        cout << idx << '\n';
    }

    return 0;
}