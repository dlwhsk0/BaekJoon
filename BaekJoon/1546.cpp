#include <iostream>

using namespace std;

/*
1. max 구하기
2. 모든 점수를 점수/max*100로 바꾸기
3. 새로운 평균 구하기
*/

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    float arr[1000] = { 0 };
    int n, i;
    float max = 0, avg = 0;
    cin >> n; // 과목 개수

    for (i = 0; i < n; i++) {
        cin >> arr[i]; // 입력

        if (max < arr[i]) { max = arr[i]; } // max
    }

    for (i = 0; i < n; i++) {
        avg += (arr[i] / max) * 100;
    }
    cout << avg / n;

    return 0;
}
