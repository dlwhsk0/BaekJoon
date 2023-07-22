#include <iostream>
#include <algorithm>
#include <cmath> // sqrt 함수
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    while (++n) {
        int a, b, count = 0, triangle = 0, square = 0;
        cin >> a >> b;

        if (a == 0 && b == 0) { break; } // 중지

        for (int i = 2; i <= 44721; i++) {
            triangle = i * (i + 1) / 2;

            if (triangle > a - 1) {
                if (triangle >= b - 1) { break; }

                square = triangle + 1;
                if (square == (int)sqrt(square) * (int)sqrt(square)) { count++; }
            }
        }
        cout << "Case " << n << ": " << count << "\n";
    }
    return 0;
}