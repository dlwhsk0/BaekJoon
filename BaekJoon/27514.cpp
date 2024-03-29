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

    int n;
    long long l; // ~2^62는 long long
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
            cout << (long long)pow(2, i); // 2^i 출력
            // !!!!!! pow는 실수형을 리턴하는데
            // 실수형은 엄청 큰 수를 표현 할 때
            // 2345e+18 이런 식으로 뒤를 잘라먹음.
            // 그래서 틀렸던 거임! 강제형변환 해주면 정답!!
            return 0;
        }
    }

    return 0;
}