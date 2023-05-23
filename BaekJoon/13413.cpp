#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
using namespace std;

/*
임의의 말 2개 체인지
말 하나 색상 체인지

최소 횟수:
목표와 다른 상태를 B, W 경우를 나누어 저장
합에서 B, W중 작은 값을 뺀다 (교환할 수 있음)
*/

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t, n, i, j, B, W, answer;
    bool flag = 1; // 1: B, 0: W
    string start, goal;

    cin >> t;
    for (i = 0; i < t; i++) {
        cin >> n;
        cin >> start;
        cin >> goal;

        B = 0; W = 0;
        for (j = 0; j < n; j++) {
            if (start[j] != goal[j]) {
                if (start[j] == 'B') { B++; }
                else { W++; }
            }
        }

        answer = B + W - min(B, W);
        cout << answer << '\n';
    }

    return 0;
}
