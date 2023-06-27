#include <string>
#include <iostream>

using namespace std;

// 돌은 1개 또는 3개, 마지막 돌을 가져가는 사람이 게임을 이기게 된다
// 홀수면 상근, 짝수면 창용

int main()
{
    int n;
    string sk = "SK";
    string cy = "CY";

    cin >> n;

    if (n % 2) { cout << sk; }
    else { cout << cy; }

    return 0;
}