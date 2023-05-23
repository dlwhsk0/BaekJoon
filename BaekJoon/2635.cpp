#include <iostream>
using namespace std;

/*
최대 개수의 두번째 숫자를 구해서 마지막에 다시 출력

numcnt 함수로 개수 구하기
*/

int numcnt(int prev, int num) {
    int next = prev - num;
    if (next < 0) return 2; // 2번째 수까지
    return numcnt(num, next) + 1;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, i, sec, count, max = 0, answer;
    cin >> n;

    for (i = 1; i <= n; i++) {
        count = numcnt(n, i);

        if (count > max) {
            max = count;
            sec = i;
        }
    }

    cout << max << '\n';
    cout << n << " " << sec;

    int temp = n - sec;
    while (temp >= 0) {
        n = sec;
        sec = temp;
        cout << " " << sec;
        temp = n - sec;
    }

    return 0;
}
