#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, num=1, ans = 0;
    cin >> n; 

    while (true) {
        if (num % 2 == 1 && n - num < 0) { ans = num - n; break; }
        else if (num % 2 == 0 && n - num < 0) { cout << 0; return 0; }
        n -= num;
        num++;
    }

    cout << ans;

    return 0;
}