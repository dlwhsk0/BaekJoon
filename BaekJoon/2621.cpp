#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

/*
1. 숫자를 오름차순으로 정렬
2. 연속된 숫자인지 검사
3. 색 동일 검사
4. 나머지 경우들 검사
*/

vector<pair<int, char>> v; // 카드 저장
int arr[10]; // 동일 숫자 개수 저장

int main() {

    int i, j, num, score;
    char color;
    bool cont = 1, same = 1;

    for (i = 0; i < 5; i++) { // 입력 받기
        cin >> color >> num;
        v.push_back({ num, color });
        arr[num]++;
    }

    sort(v.begin(), v.end()); // 숫자 오름차순 정렬

    // 연속 여부 검사
    for (i = 0; i < 5; i++) {
        if (i == 0) { num = v[i].first; continue; }
        if (v[i].first != ++num) { cont = 0; break; }
    }
    if (cont) { // 숫자가 모두 연속: 모두 같은 색인지 검사
        for (i = 0; i < 5; i++) {
            if (i == 0) { color = v[i].second; continue; }
            if (v[i].second != color) { same = 0; break; }
        }
        if (same) { cout << v[4].first + 900; return 0; }
        else { cout << v[4].first + 500; return 0; }
    }

    // 색 동일 여부 검사
    same = 1;
    for (i = 0; i < 5; i++) {
        if (i == 0) { color = v[i].second; continue; }
        if (v[i].second != color) { same = 0; break; }
    }
    if (same) { cout << v[4].first + 600; return 0; }

    // 숫자 동일 찾기
    int two = -1, twocntmax = 0, three = -1, four = -1;
    for (i = 1; i < 10; i++) {
        if (arr[i] == 2) {
            twocntmax++;
            if (twocntmax == 2) { twocntmax = max(i, two); }
            else { two = i; }
        }
        else if (arr[i] == 3) { three = i; }
        else if (arr[i] == 4) { four = i; }
    }
    if (four != -1) { score = four + 800; }
    else if (three != -1) {
        if (two != -1) { score = (three * 10) + two + 700; }
        else { score = three + 400; }
    }
    else if (two != -1) {
        if (twocntmax > 1) { score = (twocntmax * 10) + two + 300; }
        else { score = two + 200; }
    }
    else { score = v[4].first + 100; }

    cout << score;

    return 0;
}
