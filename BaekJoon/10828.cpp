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
        if (cmd == "push") { // ���� x�� ť�� �ֱ�
            cin >> X;
            arr[++top] = X;
        }
        else if (cmd == "pop") { // ���� ���� ������ ���� ����ϱ�, ������ -1
            if (top == 0) { cout << -1 << endl; }
            else { cout << arr[top--] << endl; }
        }
        else if (cmd == "size") { // ť�� ����ִ� ������ ���� ����ϱ�
            cout << top << endl;
        }
        else if (cmd == "empty") { // ť�� ��������� 1, �ƴϸ� 0 ����ϱ�
            if (top == 0) { cout << 1 << endl; }
            else { cout << 0 << endl; }
        }
        else if (cmd == "top") { // ���� ���� �ִ� ���� ����ϱ�, ������ -1
            if (top == 0) { cout << -1 << endl; }
            else { cout << arr[top] << endl; }
        }
    }

    return 0;
}
