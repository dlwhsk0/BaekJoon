#include <iostream>
#include <algorithm>

using namespace std;

/*
new: heap에 메모리를 저장한 후 주소 리턴
delete: 해당 주소의 메모리를 해제

int* ptr = new int;
delete ptr;

int* ptr = new int[2];
delete[] ptr;
*/

int main() {
    int n; // 동아리 방의 초기 개수
    cin >> n;

    int* arr = new int[n + 1];
    for (int i = 1; i <= n; i++) { // 초기 방
        arr[i] = 0;
    }

    int m; // 빌런의 행동 횟수
    cin >> m;

    int x, y;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;

        for (int j = x; j < y; j++) {
            arr[j] = 1; // 오른쪽 벽 허물기
        }
        if (arr[y] != 1) { arr[y] = -1; } // 왼쪽 벽 허물기
    }

    int count = 0;
    for (int i = 1; i <= n; i++) { // 방 개수
        if (arr[i] == 0 || arr[i] == -1) { count++; }
    }

    cout << count;

    return 0;
}
