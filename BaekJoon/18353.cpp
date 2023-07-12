#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// LIS 문제 : 최장 증가 부분 수열

int arr[2001];
vector<int> v;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, num, i, maxnum = 0;
    cin >> n;

    for (i = 0; i < n; i++) { // 입력 받기
        cin >> num;
        v.push_back(num);
    }
    reverse(v.begin(), v.end()); // 뒤집어서 오름차순 구하는 형식으로 바꾸기

    for (i = 0; i < n; i++) { // LIS
        arr[i] = 1;
        for (int j = 0; j < i; j++) {
            if (v[j] < v[i]) {
                arr[i] = max(arr[i], arr[j] + 1); // 값 업데이트
            }
        }
    }

    for (i = 0; i < n; i++) { // 최댓값
        maxnum = max(maxnum, arr[i]);
    }
    cout << n - maxnum;

    return 0;
}