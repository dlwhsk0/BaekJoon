#include <iostream>
#include <set>
using namespace std;

set<int> s; // 중복 제거를 위한 set 컨테이너 사용

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, ans, i, v, x, l;
    cin >> n;

    for (i = 0; i <= n; i++) {
        for (v = 0; v <= n - i; v++) {
            for (x = 0; x <= n - i - v; x++) { // 계산값을 넣어줌
                l = n - i - v - x;
                ans = i + v * 5 + x * 10 + l * 50;
                s.insert(ans);
            }
        }
    }

    cout << s.size();

    return 0;
}