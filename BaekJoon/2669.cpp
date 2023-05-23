#include <iostream>
using namespace std;

/*
2차원 배열을 사용해 각 직사각형을 색칠한 후 색칠된 칸의 개수 구함
*/

int main() {
    bool sq[101][101] = { 0 }; // x, y 좌표
    int x1, y1, x2, y2, i, x, y, answer = 0;

    for (i = 0; i < 4; i++) {
        cin >> x1 >> y1 >> x2 >> y2;

        for (x = x1; x < x2; x++) { // 색칠
            for (y = y1; y < y2; y++) {
                sq[x][y] = 1;
            }
        }
    }

    for (x = 0; x < 101; x++) {
        for (y = 0; y < 101; y++) {
            if (sq[x][y] == 1) { answer++; }
        }
    }
    cout << answer;

    return 0;
}
