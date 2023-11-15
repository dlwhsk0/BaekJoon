#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#define ll long long
using namespace std;

map<int, int> med;
int m[100];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, me, mn, r, l, s;
    bool flag;

    cin >> n; // 약의 종류
    for (int i = 0; i < n; i++) {
        cin >> me >> mn; // 약의 효능, 약의 이름
        med[me] = mn; // hash map
    }

    cin >> r; // 증상의 개수
    for (int i = 0; i < r; i++) {
        cin >> l; // 증상의 개수

        flag = 1; // 초기화
        for (int k = 0; k < l; k++) {
            cin >> s;
            if (med.find(s) == med.end()) { flag = 0; } // 없음 died...
            else { m[k] = med[s]; }
        }
        if (flag) { // 모두 치료 가능
            for (int z = 0; z < l; z++) { cout << m[z] << " "; }
            cout << '\n';
        }
        else { cout << "YOU DIED\n"; }
    }

    return 0;
}