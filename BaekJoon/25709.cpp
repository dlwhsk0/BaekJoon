#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;

//1. ���� �ֱ�
//2. ���� ���� ���� 1�̸� (2) ����
//(2) ���� �� front�� 0�̸� ��� pop_front() ����
//3. �ƴϸ� ���� 1�� �ڸ� �� ���ֱ� (1�� �ڸ� - 1)�� (1) �����ϰ� (2) �ѹ� ����
//4. �� ������ �� �ڸ� ���� ���� ������ �ݺ�
//5. ������ ����ŭ Ƚ�� �����ϰ� ���

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