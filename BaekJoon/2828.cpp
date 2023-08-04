#include <iostream>
using namespace std;

/*
사과가 떨어질 때마다,
바구니의 시작과 끝에 있는지 검사
시작보다 앞에 있으면 그만큼 이동
끝보다 뒤에 있으면 그만큼 이동
*/

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, j, ans = 0, i, apple; // 스크린, 바구니, 사과 개수, 이동거리
    cin >> n >> m;
    
    cin >> j;
    int start = 1, end = m;

    for (i = 0; i < j; i++) {
        cin >> apple;
        if (start > apple) { // 왼쪽으로 이동
            ans += start - apple;
            start = apple;
            end = start + (m - 1);
        }
        else if (end < apple) { // 오른쪽으로 이동
            ans += apple - end;
            end = apple;
            start = end - (m - 1);
        }
    }

    cout << ans;

    return 0;
}