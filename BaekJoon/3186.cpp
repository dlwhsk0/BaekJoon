#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// flag가 k가 되면 사용중, -l이 되면 완료 플러시 계산

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int k, l, n, kflag = 0, lflag = 0;
    bool flush = 1;
    string str;

    cin >> k >> l >> n;
    cin >> str;

    for (int i = 0; i < n; i++) {
        if (str[i] == '1') {
            lflag = 0;
            kflag++;
        }
        else if (kflag < k) { kflag = 0; }

        if (kflag >= k) { // 사용중일 때
            if (str[i] == '0') { lflag++; }

            if (lflag == l) {
                cout << i + 1 << '\n';
                flush = 0;
                kflag = 0;
            }
        }
    }

    if (kflag >= k) { // 사용중인데 주어진 시간이 끝났음 -> l초 후에 플러시가 작동함
        cout << n + l << '\n';
        flush = 0;
    }
    if (flush) { cout << "NIKAD" << '\n'; }

    return 0;
}