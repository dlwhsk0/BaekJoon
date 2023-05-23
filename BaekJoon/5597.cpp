#include <iostream>
#include <algorithm> // max()
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    bool arr[31] = { 0 }; // 0: 미제출 1: 제출
    int num;

    for (int i = 1; i <= 28; i++) { // 입력 받은 번호의 학생 제출 처리
        cin >> num;
        arr[num] = 1;
    }

    for (int i = 1; i <= 30; i++) { // 미제출 학생 번호 출력
        if (arr[i] == 0) { cout << i << endl; }
    }

    return 0;
}
