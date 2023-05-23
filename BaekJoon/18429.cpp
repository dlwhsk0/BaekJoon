#include <iostream>
using namespace std;

/*
* 하루가 지날 때마다 중량이 k 만큼 감소한다.
* N 개의 운동 키트는 N 일 동안 한 번씩만 사용할 수 있다.
* 
* DFS 백트래킹
* >> ;; int를 전역변수로 하면 안 됨
*/

int exercise[51];
bool visited[51];
int weight = 500, k, n, ans = 0;

void DFS(int dep) {
    if (dep == n) { ans++; } // 끝까지 닿으면 1 증가
    else {
        for (int i = 0; i < n; i++) {
            if (visited[i] == false) {
                visited[i] = true;
                if (weight + exercise[i] >= 500) {
                    weight += exercise[i];

                    DFS(dep + 1);
                    weight -= exercise[i]; // 백
                }
                visited[i] = false; // 방문 여부 초기화
            }
        }
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> exercise[i];
        visited[i] = false;
        exercise[i] -= k; // 증가량 - 하루 감소량 = 최종 증가량
    }

    DFS(0);
    cout << ans;

    return 0;
}