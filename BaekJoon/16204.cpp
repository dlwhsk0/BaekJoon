#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int n, m, k; // ī�� n��, o: m�� x: n-m��, �ڿ� k: o
    cin >> n >> m >> k;

    int count = 0;
    if (m < k) { count += m; }
    else { count += k; }

    m = n - m;
    k = n - k;

    if (m < k) { count += m; }
    else { count += k; }

    cout << count << endl;

    return 0;
}
