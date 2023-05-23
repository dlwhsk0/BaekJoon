#include <iostream>

using namespace std;

int main()
{
    int year;
    cin >> year;

    if (year % 4 == 0) { // 4의 배수이면서
        if (year % 100 != 0 || year % 400 == 0) { // 100의 배수가 아닐 때 또는 400의 배수일 때
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