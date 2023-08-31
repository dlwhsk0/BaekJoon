#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int ans = 0, n;
    bool m, flag;
    string str;

    cin >> n;

    while (true) {
        m = true;
        str = to_string(n);

        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '1') { // 숫자 중에 1이 있는 경우
                flag = false;
                string temp = "";
                for (int k = 0; k < str.length(); k++) {
                    if (k == i) { continue; } // 그 1을 빼고 새로운 0을 만들기

                    if (str[k] != '0') { flag = true; } // 숫자 사이에 0이 있는 경우 같이 들어가도록 하기
                    if (flag) { temp += str[k]; }
                }
                str = temp;
                m = false;
                break;
            }
        }
        ans++;

        if (str == "") { break; } // 숫자가 남지 않으면 루프 종료

        n = stoi(str);
        if (m) { n--; }
    }

    cout << ans;

    return 0;
}