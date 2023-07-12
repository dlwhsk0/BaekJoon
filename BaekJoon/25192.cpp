#include <iostream>
#include <string>
#include <set>
using namespace std;

// ���� ENTER�� �ԷµǱ� �������� �г��� ��Ͽ����� �ߺ� ���θ� �˻�
// �Ź� for �ݺ������� �ߺ��� �˻��ߴ��� �ð� �ʰ��� ���� ��? -> �ߺ��� ������� �ʴ� set �����̳� ���

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