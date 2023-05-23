#include <iostream>

using namespace std;

int main()
{
    int a, b, c, reward = 0;
    cin >> a >> b >> c;

    if (a == b && b == c) { // 같은 눈이 3개 : 10,000 + 같은눈*1,000
        reward = 10000 + a * 1000;
    }
    else if (a == b) { // 같은 눈이 2개 : 1,000 + 같은눈*100
        reward = 1000 + a * 100;
    }
    else if (a == c) {
        reward = 1000 + a * 100;
    }
    else if (b == c) {
        reward = 1000 + b * 100;
    }
    else { // 모두 다른 경우 : 그중가장큰눈*100
        if (a > b) {
            if (a > c) { // a가 제일 클 때
                reward = a * 100;
            }
        }
        else if (b > c) { // b가 제일 클 때
            reward = b * 100;
        }

        if (c > a) {
            if (c > b) { // C가 제일 클 때
                reward = c * 100;
            }
        }
    }

    cout << reward << endl;

    return 0;
}
