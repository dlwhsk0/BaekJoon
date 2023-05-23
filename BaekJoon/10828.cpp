#include <iostream>
#include <string>

using namespace std;

int main() {
    int arr[10001] = { 0 };
    int n, X, top = 0;
    string cmd;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cmd;
        if (cmd == "push") { // 정수 x를 큐에 넣기
            cin >> X;
            arr[++top] = X;
        }
        else if (cmd == "pop") { // 가장 위의 정수를 빼서 출력하기, 없으면 -1
            if (top == 0) { cout << -1 << endl; }
            else { cout << arr[top--] << endl; }
        }
        else if (cmd == "size") { // 큐에 들어있는 정수의 개수 출력하기
            cout << top << endl;
        }
        else if (cmd == "empty") { // 큐가 비어있으면 1, 아니면 0 출력하기
            if (top == 0) { cout << 1 << endl; }
            else { cout << 0 << endl; }
        }
        else if (cmd == "top") { // 가장 위에 있는 정수 출력하기, 없으면 -1
            if (top == 0) { cout << -1 << endl; }
            else { cout << arr[top] << endl; }
        }
    }

    return 0;
}
