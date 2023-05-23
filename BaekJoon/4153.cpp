#include <iostream>
#include <algorithm> // sort()
#include <cmath> // pow()
#include <vector>
#include <string>

using namespace std;

/*
무한 루프 속
1. 세 변의 길이 배열로 입력 받기
2. 오름차순으로 정렬하기
3. 피타고라스 정리 검사
*/

int main() {
    int arr[3] = { 0 };

    while (true) {
        cin >> arr[0] >> arr[1] >> arr[2]; // 세 변의 길이 입력

        if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0) { break; }
        else {
            sort(arr, arr + 3); // 오름차순 정렬

            if (pow(arr[2], 2) == (pow(arr[0], 2) + pow(arr[1], 2))) {
                cout << "right" << endl;
            } // 피타고라스 정리
            else {
                cout << "wrong" << endl;
            }
        }
    }

    return 0;
}