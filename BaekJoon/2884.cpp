#include <iostream>

using namespace std;

int main()
{
    int H, M;
    cin >> H >> M;

    // 45분 일찍으로 알람 바꾸기
    if (M < 45) {
        if (H > 0) {
            H--;
            M += (60 - 45);
        }
        else { // 0시 일 때
            H = 23;
            M += (60 - 45);
        }
    }
    else {
        M -= 45;
    }

    cout << H << " " << M << endl;

    return 0;
}
