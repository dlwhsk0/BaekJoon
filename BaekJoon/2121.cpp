#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

/*
한 점이 (x, y)일 경우
(x+a, y) / (x, y+b) / (x+a, y+b)
이렇게 3점이 존재하면 직사각형이 완성된다.

set 컨테이너 <set>
1. 중복을 없앤다
2. 순서가 상관없이 정렬되어 입력된다.
3. 인덱스로 접근할 수 없다...
*/

set<pair<int, int>> s;
vector<pair<int, int>> v;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, a, b, x, y, i, j, ans=0;
    cin >> n;
    cin >> a >> b;

    for (i = 0; i < n; i++) {
        cin >> x >> y;
        v.push_back({ x, y });
        s.insert({x, y});
    }

    for (i = 0; i < n; i++) {
        x = v[i].first;
        y = v[i].second;

        if (s.find({ x + a, y }) != s.end() && s.find({ x + a, y + b }) != s.end() && s.find({ x, y + b }) != s.end()) { ans++; }
    }
    cout << ans;

    return 0;
}