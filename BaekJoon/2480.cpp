#include <iostream>

using namespace std;

int main()
{
    int a, b, c, reward = 0;
    cin >> a >> b >> c;

    if (a == b && b == c) { // ���� ���� 3�� : 10,000 + ������*1,000
        reward = 10000 + a * 1000;
    }
    else if (a == b) { // ���� ���� 2�� : 1,000 + ������*100
        reward = 1000 + a * 100;
    }
    else if (a == c) {
        reward = 1000 + a * 100;
    }
    else if (b == c) {
        reward = 1000 + b * 100;
    }
    else { // ��� �ٸ� ��� : ���߰���ū��*100
        if (a > b) {
            if (a > c) { // a�� ���� Ŭ ��
                reward = a * 100;
            }
        }
        else if (b > c) { // b�� ���� Ŭ ��
            reward = b * 100;
        }

        if (c > a) {
            if (c > b) { // C�� ���� Ŭ ��
                reward = c * 100;
            }
        }
    }

    cout << reward << endl;

    return 0;
}
