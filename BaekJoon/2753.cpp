#include <iostream>

using namespace std;

int main()
{
    int year;
    cin >> year;

    if (year % 4 == 0) { // 4�� ����̸鼭
        if (year % 100 != 0 || year % 400 == 0) { // 100�� ����� �ƴ� �� �Ǵ� 400�� ����� ��
            cout << 1;
        }
        else {
            cout << 0;
        }
    }
    else {
        cout << 0;
    }

    return 0;
}