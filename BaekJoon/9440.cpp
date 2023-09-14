#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// �������� �����ϰ� �տ�������(���� ������) ������ ���ʿ� �־��ֱ�
// 0�� �� ������ ���� �� ��

int arr[15];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, zero, ans;
    string a, b;
    while (true) {
        cin >> n;
        if (n == 0) { return 0; }

        for (int i = 0; i < n; i++) { cin >> arr[i]; }
        sort(arr, arr + n);
        a = ""; b = ""; zero = 0;
        
        // arr�� ���� �� �� ���ڰ� 0�� �ƴϰ� �ٲٱ�
        for (int i = 0; i < n; i++) { if (arr[i] == 0) { zero++; } }
        if (zero == 1) { swap(arr[0], arr[2]); }
        else if (zero > 1) {
            swap(arr[0], arr[zero]);
            swap(arr[1], arr[zero + 1]);
        }

        for (int i = 0; i < n; i++) { // a, b �ϳ��� ��������
            if (i % 2 == 0) { a += to_string(arr[i]); }
            else { b += to_string(arr[i]); }
        }
        ans = stoi(a) + stoi(b);
        cout << ans << '\n';
    }

    return 0;
}