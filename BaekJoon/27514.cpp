#include <iostream>
#include <algorithm>
#include <cmath> // log2(), pow()
using namespace std;

// 1. 입력받는 수를 모두 log2 처리 해서 지수들만 구해 배열에 저장한다.
// 2. 앞에서부터 2로 나눠 짝이 되는 수 만큼 다음 지수의 수에 더해준다.
// 3. 뒤에서부터 검사해 가장 큰 수를 찾아내 제곱해 원래의 수를 구해 답을 구한다.

int arr[63]; // 2의 0~62 제곱의 개수

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, l;
    cin >> n;

    for (int i = 0; i < n; i++) { // 입력
        cin >> l;
        if (l != 0) { // log2 처리로 지수를 뽑아내 개수를 1 증가한다.
            l = log2(l);
            arr[l]++;
        }
    }

    for (int i = 0; i < 62; i++) {
        arr[i + 1] += arr[i] / 2;
    }

    for (int i = 62; i >= 0; i--) {
        if (arr[i] != 0) {
            cout << pow(2, i);
            return 0;
        }
    }

    return 0;
}