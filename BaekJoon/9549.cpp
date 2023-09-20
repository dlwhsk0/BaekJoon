#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#define ll long long
using namespace std;

// 슬라이딩 윈도우 알고리즘

int alphabet[26]; // 암호화된 비밀번호 알파벳 카운트
int result[26]; // 정답 비밀번호의 알파벳 카운트
int lenres, lenori;
string res, origin;

bool check() { // 원래 비밀번호와 빈도수 비교
    bool ans = true;
    for (int i = 0; i < lenori; i++) {
        if (alphabet[((int)origin[i] - 'a')] != result[((int)origin[i] - 'a')]) { ans = false; break; }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    bool c;
    cin >> t;

    for (int k = 0; k < t; k++) {
        cin >> res;
        cin >> origin;

        lenres = res.length(); // 초기화
        lenori = origin.length();
        fill_n(alphabet, 26, 0);
        fill_n(result, 26, 0);
        c = false;

        for (int i = 0; i < lenori; i++) { // 답안 생성 및 첫번째 빈도 저장
            result[(int)(origin[i] - 'a')]++;
            alphabet[(int)(res[i] - 'a')]++;
        }
        if (check()) { c = true; }
        else {
            for (int i = lenori; i < lenres; i++) {
                alphabet[((int)res[i] - 'a')]++; // 이전 알파벳 빈도 삭제
                alphabet[((int)res[i - lenori] - 'a')]--; // 다음 알파벳 빈도 추가
                
                if (check()) { c = true; break; }
            }
        }

        if (c) { cout << "YES" << '\n'; }
        else { cout << "NO" << '\n'; }
    }

    return 0;
}