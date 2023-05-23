#include <iostream>

using namespace std;

/*
1. �� �ڸ��� ���ڸ� ���Ѵ�. 26) 2 + 6 = 8 -> 68
2. 68) 6 + 8 = 14 -> 84
*/

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int cycle, newn = -1, temp = n;

    // for���� ����غ���
    for (cycle = 0; newn != n; cycle++) {
        if (temp < 10) { temp = temp * 10 + temp; }
        else {
            temp = ((temp % 10) * 10) + (((temp / 10) + (temp % 10)) % 10);
        }
        newn = temp;
    }

    cout << cycle;

    return 0;
}
