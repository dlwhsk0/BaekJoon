#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
using namespace std;

/*
R = 4, G = 8
선수 1명에게 빨간 사과 4개와 초록 사과 8개를 줄 수 있다.
선수 2명에게 빨간 사과 2개와 초록 사과 4개를 각각 줄 수 있다.
선수 4명에게 빨간 사과 1개와 초록 사과 2개를 각각 줄 수 있다.

최대 선수는 두 사과 중 작은 개수
둘 다 나누어 떨어져야 함
=>브루트포스는 시간 초과
==>gcd 최대공약수 구하기
*/

int gcd(int a, int b) { // 최대공약수
    int temp, num;

    if (a < b) { // 큰 수를 a로
        temp = a;
        a = b;
        b = temp;
    }

    while (b != 0) {
        num = a % b;
        a = b;
        b = num;
    }

    return a;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int r, g, player, i, num;
    cin >> r >> g;

    //player = min(r, g);
    num = gcd(r, g);

    for (i = 1; i <= num; i++) {
        if (num % i == 0) {
            cout << i << " " << r / i << " " << g / i << '\n';
        }
    }

    return 0;
}