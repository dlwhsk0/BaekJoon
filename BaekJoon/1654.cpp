#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int arr[10001] = { 0 };
    int k, n, count, res = 0;
    cin >> k >> n;

    for (int i = 0; i < k; i++) { // k개의 랜선 길이 입력
        cin >> arr[i];
    }

    // k개의 랜선 중 최댓값 구하기
    int max = *max_element(arr, arr + k);

    long long low, mid, high; // 이진 탐색 위한 변수
    low = 1; high = max;

    while (low <= high) {
        mid = (low + high) / 2;
        count = 0;

        // 만들어지는 랜선 개수 합산
        for (int i = 0; i < k; i++) {
            count += arr[i] / mid;
        }

        // mid 길이로 잘랐을 때
        // n개 이상의 랜선이 만들어지면 더 길게
        // 안 만들어지면 더 짧게
        if (count >= n) {
            low = mid + 1;
            if (res < mid) res = mid;
        }
        else { high = mid - 1; }
    }

    cout << res;

    /* 시간초과 반복문 코드
    for(int i=max; i>0; i--) {
        count = 0;

        for(int a=0; a<k; a++) {
            count += arr[a]/i;
        }

        if(count >= n) {
            cout << i;
            break;
        }
    }*/

    return 0;
}