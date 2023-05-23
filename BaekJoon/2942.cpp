#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
using namespace std;

/*
R = 4, G = 8
���� 1���� ���� ��� 4���� �ʷ� ��� 8���� �� �� �ִ�.
���� 2���� ���� ��� 2���� �ʷ� ��� 4���� ���� �� �� �ִ�.
���� 4���� ���� ��� 1���� �ʷ� ��� 2���� ���� �� �� �ִ�.

�ִ� ������ �� ��� �� ���� ����
�� �� ������ �������� ��
=>���Ʈ������ �ð� �ʰ�
==>gcd �ִ����� ���ϱ�
*/

int gcd(int a, int b) { // �ִ�����
    int temp, num;

    if (a < b) { // ū ���� a��
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