#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;

//1. 덱에 넣기
//2. 가장 앞의 수가 1이면 (2) 수행
//(2) 수행 시 front가 0이면 계속 pop_front() 수행
//3. 아니면 가장 1의 자리 수 없애기 (1의 자리 - 1)번 (1) 수행하고 (2) 한번 수행
//4. 위 과정을 한 자리 수만 남을 때까지 반복
//5. 마지막 수만큼 횟수 증가하고 출력

deque<int> dq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int ans = 0;
    string str;
    cin >> str;

    //cout << "*** ans: " << ans << '\n';
    int len = str.length();
    for (int i = 0; i < len; i++) { dq.push_back((int)(str[i]-'0')); }

    while (dq.size() > 1) {
        if (dq.front() == 1) {
            ans++;
            dq.pop_front();
            while (dq.front() == 0 && dq.size() > 1) { dq.pop_front(); }
            //cout << "*** ans: " << ans << '\n';
        }
        else {
            if (dq.back() == 0) {
                ans++;

            }
            ans += dq.back();
            dq.pop_back();
            //cout << "*** ans: " << ans << '\n';
        }
    }

    ans += dq.back();
    cout << ans;

    return 0;
}