#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int arr[1000000] = { 0 };
    int n, m;
    long long sum, height = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++) { // n개의 나무 높이 입력
        cin >> arr[i];
    }

    // n개의 나무 중 최댓값 구하기
    long long max = *max_element(arr, arr + n);

    long long low, mid, high; // 이진 탐색 위한 변수
    low = 1; high = max;

    while (low <= high) {
        mid = (low + high) / 2;
        sum = 0;

        // 절단하고 남은 나무 길이
        for (int i = 0; i < n; i++) {
            if (arr[i] > mid) sum += arr[i] - mid;
        }

        // mid 높이로 설정했을 때
        // m 이상의 나무가 남으면 더 높게
        // 모자라면 더 짧게
        if (sum >= m) {
            low = mid + 1;
            if (height < mid) height = mid;
        }
        else { high = mid - 1; }
    }

    cout << height;

    return 0;
}