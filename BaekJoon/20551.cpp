#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

/*
a 원소들 오름차순
m개 질문: 정수 d가
b에서 가장 먼저 등장한 위치
오름차순과 이분 탐색?
이분탐색으로 찾고 찾아내면 가장 먼저인 위치를 찾아야함
존재하지 않으면 -1
*/

vector<long long> v;

int binary_search(long long num, int start, int end) {
    int mid = (start + end) / 2;
    if (start > end) { return -1; }

    if (v[mid] == num) {
        for (int i = mid - 1; i >= 0; i--) {
            if (v[i] == num) { mid = i; }
            else { break; }
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