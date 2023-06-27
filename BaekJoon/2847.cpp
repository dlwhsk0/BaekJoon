#include <iostream>
using namespace std;

int score[101];

int main() {
    int n, i, j, temp, ans = 0;
    cin >> n;

    for (i = 0; i < n; i++) { // 입력 받기
        cin >> score[i];

        if (i > 0) {
            for (j = i - 1; j >= 0; j--) {
                if (score[j] >= score[j + 1]) {
                    temp = score[j] - score[j + 1] + 1;
                    score[j] -= temp;
                    ans += temp;
                }
            }
        }
    }
    cout << ans;

    return 0;
}