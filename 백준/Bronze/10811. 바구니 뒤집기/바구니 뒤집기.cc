#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#define ll long long
using namespace std;

int arr[101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, i, j, k, temp;

    cin >> n >> m;
    for (int a = 1; a <= n; a++) { arr[a] = a; }

    for (int a = 0; a < m; a++) {
        cin >> i >> j;
        for (int b = i; b <= j; b++) {
            temp = arr[b];
            arr[b] = arr[j];
            arr[j] = temp;
            j--;
        }
    }

    for (int a = 1; a <= n; a++) { cout << arr[a] << " "; }

    return 0;
}