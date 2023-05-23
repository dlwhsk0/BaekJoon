#include <iostream>
#include <algorithm>
using namespace std;

/*
여러 채의 집 중 한 개의 안테나 설치 (동일한 위치에 여러개 가능)
모든 집까지의 거리의 총 합이 최소가 되도록

배열 정렬한 후 중앙값
*/

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, i;
    cin >> n;

    int* arr = new int[n];
    for (i = 0; i < n; i++) { cin >> arr[i]; }

    sort(arr, arr + n);
    cout << arr[(n - 1) / 2];

    return 0;
}