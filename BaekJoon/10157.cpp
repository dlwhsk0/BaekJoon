#include <iostream>
// #include <iomanip> // setw()
using namespace std;

/*
������ �˰��� ���

1. x ����, y �����ϸ鼭 ���� ������� �� �� ���� �� ����--
2. y ����, x �����ϸ鼭 ���� ������� �� �� ���� �� ����--
3. ��������� �ְ� ���� 1 2 �ݺ�
�ϴٰ� k ��ȣ�� �ش��ϸ� ��ġ ����ϰ� ����
*/

int seat[1001][1001] = { 0 };
int c, r, k; // ���� ũ��, ��� ��ȣ

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> c >> r;
    cin >> k;

    int x = 1, y = 0, sw = 1, xlimit = c-1, ylimit = r, num = 0, i, j;
    if (k <= c * r) {
        while (true) {
            for (j = 1; j <= ylimit; j++) { // x �����ϰ� y�� ����
                y += sw;
                seat[x][y] = ++num;
                // cout << "seat[" << x << "][" << y << "] = " << num << '\n';

                if (num == k) { cout << x << " " << y; return 0; }
            }
            ylimit--;
            // cout << "ylimit-- : " << ylimit << '\n';

            for (i = 1; i <= xlimit; i++) { // y �����ϰ� x�� ����
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