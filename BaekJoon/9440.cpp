#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// 오름차순 정렬하고 앞에서부터(작은 수부터) 번갈아 양쪽에 넣어주기
// 0은 맨 앞으로 가면 안 됨

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
        
        // arr의 제일 앞 두 숫자가 0이 아니게 바꾸기
        for (int i = 0; i < n; i++) { if (arr[i] == 0) { zero++; } }
        if (zero == 1) { swap(arr[0], arr[2]); }
        else if (zero > 1) {
            swap(arr[0], arr[zero]);
            swap(arr[1], arr[zero + 1]);
        }

        for (int i = 0; i < n; i++) { // a, b 하나씩 양쪽으로
            if (i % 2 == 0) { a += to_string(arr[i]); }
            else { b += to_string(arr[i]); }
        }
        ans = stoi(a) + stoi(b);
        cout << ans << '\n';
    }

    return 0;
}