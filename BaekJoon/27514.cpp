#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<long long> v;
int n, i, k;
long long a, ans = 0;
bool flag;

// 처음 걸 a 넣고 쭉 돌리다가 똑같은게 나오면(0 제외) 그걸 0으로 만들고 a를 두배로 바꿈
// 다시 처음으로 돌아와서 돌리기
// a가 마지막까지가면 그때 종료

void number() {
    for (i = 0; i < n; i++) {
        if (v[i] != 0) {
            cout << "* " << i << ": " << v[i] << '\n';
            for (k = 0; k < n; k++) {
                if (k != i && v[k] == v[i]) {
                    cout << "*** " << k << ": " << v[k] << '\n';
                    v[i] *= 2;
                    v[k] = 0;
                    flag = true;
                    for (long long a : v) { cout << a << " "; }
                    cout << '\n';
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) { // 입력
        cin >> a;
        if (a != 0) { v.push_back(a); } // 0이 아닌 경우에만 삽입
    }

    for (long long a : v) { cout << a << " "; }
    cout << '\n';

    n = (int)v.size();
    flag = true;

    while (flag) {
        flag = false;
        number();
        cout << "끝의 flag는?: " << flag << '\n';
    }

    for (long long a : v) { ans = max(a, ans); }

    cout << ans;

    return 0;
}