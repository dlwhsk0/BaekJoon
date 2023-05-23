#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
** 정렬 후 각 원소의 양쪽 길이 중 짧은 길이 저장
1) if 첫번째 원소: answer += v[i+1] - v[i];
2) else if 마지막 원소: { answer += v[i] - v[i - 1]; }
3) else: answer += min(v[i+1] - v[i], v[i] - v[i-1]);

1번째 시도: 31점 ?? 왜지? --> 색이 흑백 두개만 있는게 아니었음!

2차원 배열 [색상][숫자]
색상 완전 탐색
1) 색상 존재 유무 검사 없으면 continue
2) ** 정렬 후 각 원소의 양쪽 길이 중 짧은 길이 저장
*/

vector<int> v[5000];

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, num, color, i, j, size;
    long long answer = 0;

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> num >> color;
        v[color].push_back(num);
    }

    for (i = 0; i < 5000; i++) { // 색상 기준 검사
        if (v[i].empty()) { continue; }

        sort(v[i].begin(), v[i].end()); // 정렬

        size = v[i].size() - 1;
        answer += (v[i][1] - v[i][0]) + (v[i][size] - v[i][size-1]);

        for (j = 1; j < size; j++) { answer += min(v[i][j + 1] - v[i][j], v[i][j] - v[i][j - 1]); }
    }
    
    cout << answer;

    return 0;
}