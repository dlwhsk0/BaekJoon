#include <iostream>
using namespace std;

int main() {
    int n, i, temp, flag, count = 1;
    cin >> n;

    if (n == 1) {
        cout << 666;
        return 0;
    }

    for (i = 1666; ; i++) {
        temp = i;
        flag = 0;

        while (temp) { // temp°¡ 0ÀÌ µÇ¸é ¸ØÃã
            if (temp % 1000 == 666) { flag = 1; }
            temp /= 10;
        }
        if (flag) {
            count++;
            if (count == n) { break; }
        }
    }
    cout << i;

    return 0;
}