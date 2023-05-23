#include <iostream>
#include <algorithm> // min(), max()
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, i;
    cin >> n;
    int* arr = new int[n];

    for (i = 0; i < n; i++) { // 정수 입력
        cin >> arr[i];
    }

    int nmax = -1000000, nmin = 1000000;
    for (i = 0; i < n; i++) { // 최대 최솟값 구하기
        nmax = max(nmax, arr[i]);
        nmin = min(nmin, arr[i]);
    }

    cout << nmin << " " << nmax;

    // delete[] arr;


    return 0;
}
