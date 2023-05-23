#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, i, v, count = 0;
    int arr[100] = { 0 };
    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> v;

    for (i = 0; i < n; i++) {
        if (arr[i] == v) { count++; }
    }

    cout << count;

    return 0;
}
