#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#define ll long long
using namespace std;

// L원, t년 이후 2*L^t

set<int, greater<int>> s; // 내림차순

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t, l, money = 5000000, year, total; // 가진 돈
    cin >> t;

    for (int i = 0; i < t; i++) {

        s.clear(); // 초기화
        while (true) { // 입력
            cin >> l;
            if (l == 0) { break; } // 0일 때 중단
            else { s.insert(l); }
        }

        year = 1; total = 0; // 초기화
        for (int k : s) {
            total += 2 * pow(k, year);

            if (total > money) { cout << "Too expensive" << '\n'; break; }
            year++;
        }
        if (total <= money) { cout << total << '\n'; }

    }

    return 0;
}