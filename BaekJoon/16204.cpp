#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int n, m, k; // 카드 n개, o: m개 x: n-m개, 뒤에 k: o
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
