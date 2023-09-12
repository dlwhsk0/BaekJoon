#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// 문자열을 p의 개수만큼 옆으로 옮겨가며 검사
// ㄴ 새로 검사가 아니라 바뀐 알파벳만 증감해줌

int rule[4];
int cnt, a, c, g, t;

void addCount(char i) {
    if (i == 'A') { a++; }
    else if (i == 'C') { c++; }
    else if (i == 'G') { g++; }
    else { t++; }
}

void minCount(char i) {
    if (i == 'A') { a--; }
    else if (i == 'C') { c--; }
    else if (i == 'G') { g--; }
    else { t--; }
}

void check() {
    if (a >= rule[0] && c >= rule[1] && g >= rule[2] && t >= rule[3]) { cnt++; }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int s, p;
    string str;

    cin >> s >> p; // 입력
    cin >> str;
    for (int i = 0; i < 4; i++) { cin >> rule[i]; }

    for (int i = 0; i < p; i++) { addCount(str[i]); } // 처음 비밀번호
    check();

    for (int i = p; i < s; i++) {
        minCount(str[i - p]); // 가장 앞의 알파벳 개수 감소
        addCount(str[i]); // 다음 알파벳 개수 증가
        check();
    }
    cout << cnt;

    return 0;
}