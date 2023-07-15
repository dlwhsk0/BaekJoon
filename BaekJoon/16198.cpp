#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 모든 경우의 수를 검사하면서 최댓값을 출력
// 백트래킹이란? (= 퇴각검색) 해를 찾는 도중 해가 아니면 되돌아가서 다시 찾는 기법

int n, num, ans = 0;
vector<int> v;

void dfs(int sum) {
    int add, tmp;

    if (v.size() == 2) { // 첫번째와 마지막만 남은 경우 : 탐색 끝
        ans = max(ans, sum); // 최댓값 넣기
        return;
    }

    for (int i = 1; i < v.size() - 1; i++) {
        add = v[i - 1] * v[i + 1]; // 합
        tmp = v[i]; // 제거할 구슬 저장

        v.erase(v.begin() + i); // i번째 구슬 제거
        dfs(sum + add); // 다음 깊이 탐색
        v.insert(v.begin() + i, tmp); // 되돌려주는 작업 : 백트래킹 위함
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> n;
    
    for (int i = 0; i < n; i++) { // 입력
        cin >> num;
        v.push_back(num);
    }

    dfs(0);
    cout << ans;

    return 0;
}