#include <iostream>

using namespace std;

int main() {
    int x, n;
    cin >> x;
    cin >> n;

    int a, b, sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a >> b; // ���� a ���� b

        sum += a * b;
    }

    if (x == sum) { cout << "Yes"; }
    else { cout << "No"; }


    return 0;
}
