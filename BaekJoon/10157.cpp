#include <iostream>
// #include <iomanip> // setw()
using namespace std;

/*
달팽이 알고리즘 사용

1. x 고정, y 증가하면서 숫자 순서대로 한 줄 넣은 후 리밋--
2. y 고정, x 증가하면서 숫자 순서대로 한 줄 넣은 후 리밋--
3. 역순서대로 넣게 과정 1 2 반복
하다가 k 번호에 해당하면 위치 출력하고 종료
*/

int seat[1001][1001] = { 0 };
int c, r, k; // 극장 크기, 대기 번호

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> c >> r;
    cin >> k;

    int x = 1, y = 0, sw = 1, xlimit = c-1, ylimit = r, num = 0, i, j;
    if (k <= c * r) {
        while (true) {
            for (j = 1; j <= ylimit; j++) { // x 고정하고 y만 증감
                y += sw;
                seat[x][y] = ++num;
                // cout << "seat[" << x << "][" << y << "] = " << num << '\n';

                if (num == k) { cout << x << " " << y; return 0; }
            }
            ylimit--;
            // cout << "ylimit-- : " << ylimit << '\n';

            for (i = 1; i <= xlimit; i++) { // y 고정하고 x만 증감
                x += sw;
                seat[x][y] = ++num;
                // cout << "seat[" << x << "][" << y << "] = " << num << '\n';

                if (num == k) { cout << x << " " << y; return 0; }
            }
            xlimit--;
            // cout << "xlimit-- : " <<  xlimit << '\n';
            if (ylimit <= 0) { break; }

            sw *= -1;
            // cout << "sw *= -1 : " << sw << '\n';
        }
    }
    else {
        cout << 0;
    }

    /*
    for (x = 1; x <= c; x++) {
        for (y = 1; y <= r; y++) {
            cout << setw(3) << seat[x][y] << " ";
        }
        cout << '\n';
    }*/

    return 0;
}