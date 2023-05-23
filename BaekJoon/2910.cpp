#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

/*
빈도 정렬 - 많이 등장하는 빈도 순대로 정렬
빈도가 같다면 먼저 나온 것이 앞

두 개의 map을 이용하여 정렬
*/

map<int, int> od; // 숫자와 순서

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    if (a.second == b.second) { // 빈도가 같다면
        return od[a.first] < od[b.first]; // 먼저 나온 것이 앞
    }
    else {
        return a.second > b.second; // 빈도 순
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, c, num, i; // 메시지 길이, 보다 작거나 같다
    cin >> n >> c;

    map<int, int> m; // 숫자와 빈도
    for (i = 0; i < n; i++) {
        cin >> num;
        m[num]++;

        if (od[num] == 0) { od[num] = i + 1; } // 순서 저장
    }

    // value 값으로 정렬하기위해 벡터로 이동
    vector<pair<int, int>> vec(m.begin(), m.end());

    sort(vec.begin(), vec.end(), cmp);

    for (auto v : vec) { // 출력
        for (i = 0; i < v.second; i++) { // 빈도수(개수)만큼 출력
            cout << v.first << " ";
        }
    }

    return 0;
}
