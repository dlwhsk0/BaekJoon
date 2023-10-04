#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#define ll long long
using namespace std;

/*
* 역으로 브루트포스
* 점프대의 높이가 칸의 범위를 벗어나면 그 칸의 답은 1
*/

int h[200001];
int arr[200001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) { cin >> h[i]; } // 입력

    if (n == 1) { cout << 1; return 0; } // 칸이 1개면 답도 1

    for (int i = n - 1; i >= 0; i--) { // 역순으로 브루트포스
        if (i == n - 1) { arr[i] = 1; } // 마지막 칸의 답은 1
        else {
            if (h[i] > (n - i)) { arr[i] = 1; } // 점프대가 칸의 범위를 넘어가면 1
            else { arr[i] = arr[i + (h[i] + 1)] + 1; }
        }
    }

    for (int i = 0; i < n; i++) { cout << arr[i] << " "; }

    return 0;
}