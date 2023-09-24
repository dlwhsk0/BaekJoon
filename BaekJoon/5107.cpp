#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#define ll long long
using namespace std;

string name[20];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    
    while (true) {
        cin >> n;
        if (n == 0) { return 0; }
        for (int i = 0; i < n; i++) { cin >> name[i]; }
    }

    return 0;
}