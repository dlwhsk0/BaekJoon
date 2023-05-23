#include <iostream>
using namespace std;

int sum(int c) { // 분해합 구하는 함수
    int result = c;

    for (int i = c; i > 0; i /= 10) {
        result += i % 10;
    }
    return result;
}

int main() {
    int n, a, flag = 1, result;
    cin >> n;

    for (int i = n - 1; i > 1; i--) {
        if (sum(i) == n) {
            result = i;
            flag = 0;
        }
    }
    if (flag) { cout << "0"; }
    else { cout << result; }

    return 0;
}