#include <iostream>

using namespace std;

/*
입력이 끝날 때까지 A+B를 출력하는 문제. EOF에 대해 알아 보세요.
cin.eof() 활용: cin으로 입력받은 값이 없으면 true 반환
*/

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);

    int a, b;

    while (true) {
        cin >> a >> b;
        if (cin.eof()) { return 0; }
        else { cout << a + b << endl; }
    }

    return 0;
}
