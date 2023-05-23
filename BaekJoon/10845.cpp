#include <iostream>
#include <string>

using namespace std;

int main() {
    int arr[10001] = { 0 };
    int n, X, top = 0, rear = 0;
    string cmd;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cmd;
        if (cmd == "push") { // ���� x�� ť�� �ֱ�
            cin >> X;
            arr[++rear] = X;
        }
        else if (cmd == "pop") { // ���� ���� ������ ���� ����ϱ�, ������ -1
            if ((rear - top) == 0) { cout << -1 << endl; }
            else { cout << arr[++top] << endl; }
        }
        else if (cmd == "size") { // ť�� ����ִ� ������ ���� ����ϱ�
            cout << (rear - top) << endl;
        }
        else if (cmd == "empty") { // ť�� ��������� 1, �ƴϸ� 0 ����ϱ�
            if ((rear - top) == 0) { cout << 1 << endl; }
            else { cout << 0 << endl; }
        }
        else if (cmd == "front") { // ���� �տ� �ִ� ���� ����ϱ�, ������ -1
            if ((rear - top) == 0) { cout << -1 << endl; }
            else { cout << arr[top + 1] << endl; }
        }
        else if (cmd == "back") { // ���� ���� �ִ� ���� ����ϱ�, ������ -1
            if ((rear - top) == 0) { cout << -1 << endl; }
            else { cout << arr[rear] << endl; }
        }
    }

    return 0;
}
