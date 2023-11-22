#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#define ll long long
using namespace std;

map<int, int> a;
map<int, int> b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, anum, aa, bnum, bb;

    cin >> n;

    for (int i = 0; i < n; i++) {
        a.clear();
        b.clear();

        cin >> anum;
        for (int j = 0; j < anum; j++) {
            cin >> aa;
            a[aa]++;
        }

        cin >> bnum;
        for (int j = 0; j < bnum; j++) {
            cin >> bb;
            b[bb]++;
        }

        bool check = 1;
        for (int j = 4; j > 0; j--) {
            if (a[j] > b[j]) {
                cout << "A\n"; check = 0; break;
            }
            else if (a[j] < b[j]) { cout << "B\n"; check = 0; break; }
        }
        if (check) { cout << "D\n"; }
    }

    return 0;
}