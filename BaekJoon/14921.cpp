#include <iostream>
#include <algorithm>
using namespace std;

/*
투 포인터 알고리즘:
리스트에 순차적으로 점근해야할 때 두 개의 점 위치를 기록하며 처리

반복문 {
0에 가까운 수 저장
sum < 0: left 1 증가
sum > 0: right 1 감소
sum == 0: 답 찾음 break 하고 답 출력 }
*/

int arr[100000];

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, i, left, answer, right, sum;
    cin >> n;

    answer = 200000000;
    left = 0; right = n - 1;

    for (i = 0; i < n; i++) { cin >> arr[i]; }
    sort(arr, arr + n);

    while (left < right) {
        sum = arr[left] + arr[right]; // 용액 더하기
        if (abs(sum) < abs(answer)) { answer = sum; } // 0에 더 가까운 수 저장

        if (sum == 0) { break; }
        else if (sum < 0) { left++; }
        else { right--; }
    }

    cout << answer;

    return 0;
}

