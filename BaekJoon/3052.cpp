#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int arr[42] = { 0 };
    int num, i, count = 0;

    for (i = 0; i < 10; i++) {
        cin >> num;
        num = num % 42;
        arr[num] = 1;
    }

    for (i = 0; i < 42; i++) {
        if (arr[i] == 1) { count++; }
    }
    cout << count;


    return 0;
}
