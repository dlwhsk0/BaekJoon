#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

/*
빈도, 길이, 알파벳
map은 기본 오름차순

map을 value 값으로 정렬하기
1. map을 vector로 이동
2. vector를 second기준으로 정렬
*/

bool cmp(pair<string, int>& a, pair<string, int>& b) {
    if (a.second == b.second) { // 빈도가 같을 경우
        if (a.first.size() == b.first.size()) {
            return a.first < b.first; // 오름차순 
        }
        else {
            return a.first.size() > b.first.size();
        }
    }
    else {
        return a.second > b.second;
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    map <string, int> mp; // 단어와 빈도가 저장될 map
    string str;
    int n, m, i; // 단어 개수, 암기 길이
    cin >> n >> m;

    for (i = 0; i < n; i++) {
        cin >> str;

        if (str.length() >= m) { // m 이상 길이면 map에 삽입
            if (mp.find(str) == mp.end()) { mp[str] = 1; }
            else { mp[str]++; }
        }
    }

    vector<pair<string, int>> vec(mp.begin(), mp.end()); // map을 vector로 이동

    sort(vec.begin(), vec.end(), cmp);

    for (auto iter : vec) {
        cout << iter.first << '\n';
    }

    return 0;
}