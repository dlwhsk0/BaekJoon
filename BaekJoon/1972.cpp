#include <iostream>
#include <string>
#include <set>
using namespace std;

/*
string str, temp, ans;
str: 문제 문자열
temp: 각 D-쌍을 잠시 저장할 문자열
ans: D-유일을 검사하기 위해 쌍들을 저장할 문자열
*/

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, i, j;
    string str, temp="", ans;
    bool check = 1; 

    while (1) {
        check = 1;
        cin >> str;
        if (str == "*") { return 0; }

        n = str.length();
        if (n == 1) { check = 1; }
        else {
            for (i = 0; i <= n - 2; i++) { // 0쌍 부터 n-2쌍 까지
                //cout << "\n***" << i << "***" << '\n';
                ans.clear();
                check = 1
                for (j = 0; j < n-i-1; j++) {
                    temp.clear();
                    temp += str[j];
                    temp += str[j + i + 1];
                    //cout << "*Temp = " << temp << '\n';

                    if (ans.find(temp) != string::npos) { // 중복 있음
                        check = 0;
                        break;
                    }
                    else {
                        ans += temp;
                        ans += "/"; // 구분을 위해 슬래시를 넣어줌
                    }
                    //cout << "**ans = " << ans << '\n';
                }
            }
        }

        if (check) { cout << str << " is surprising.\n"; }
        else { cout << str << " is NOT surprising.\n"; }
    }

    return 0;
}
