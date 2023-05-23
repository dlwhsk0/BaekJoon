#include <iostream>
using namespace std;

/*
10번 반복 { 입력 받기 }
10번 반복 {
    100이 넘기 전까지 합계 저장
    100이 넘으면 이전 합계와 비교해서 100에 가까운 수 출력 후 중단
}
*/

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int arr[10] = { 0 };
    int i, sum = 0, temp, a, b;

    for (i = 0; i < 10; i++) { cin >> arr[i]; }

    for (i = 0; i < 10; i++) {
        temp = arr[i];
        sum += temp;

        if (sum >= 100) { break; }
    }

    a = 100 - (sum - temp);
    b = sum - 100;

    if (a == b || a > b) { cout << sum; }
    else { cout << sum - temp; }

    return 0;
}