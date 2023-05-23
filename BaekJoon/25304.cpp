#include <iostream>

using namespace std;

int main() {
    int x, n;
    cin >> x;
    cin >> n;

    int a, b, sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a >> b; // 가격 a 개수 b

        sum += a * b;
    }

    if (x == sum) { cout << "Yes"; }
    else { cout << "No"; }


    return 0;
}
