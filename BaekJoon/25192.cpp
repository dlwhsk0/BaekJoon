#include <iostream>
#include <string>
#include <set>
using namespace std;

// 다음 ENTER가 입력되기 전까지의 닉네임 기록에서의 중복 여부를 검사
// 매번 for 반복문으로 중복을 검사했더니 시간 초과가 나는 듯? -> 중복을 허용하지 않는 set 컨테이너 사용

set<string> s;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n, i, ans = 0;
    string str;
    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> str;
        if (str == "ENTER") {
            ans += s.size();
            s.clear();
        }
        else {
            s.insert(str);
        }
    }
    ans += s.size();
    cout << ans;

    return 0;
}