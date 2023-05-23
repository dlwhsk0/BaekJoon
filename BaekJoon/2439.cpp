#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = n; j > 0; j--) {
            if (j <= i) { cout << "*"; }
            else { cout << " "; }
        }
        cout << endl;
    }

    return 0;
}
