#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int arr[10000] = { 0 };
    int n, x, i;
    cin >> n >> x;

    for (i = 0; i < n; i++) { // ���� n�� �Է�
        cin >> arr[i];
    }

    for (i = 0; i < n; i++) { // x���� ���� �� ���
        if (arr[i] < x) { cout << arr[i] << " "; }
    }

    return 0;
}
