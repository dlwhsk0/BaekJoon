#include <iostream>
#include <algorithm> // max()
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int arr[10] = { 0 };
    for (int i = 1; i < 10; i++) { // �ڿ��� �Է�
        cin >> arr[i];
    }

    int nmax = 0;
    for (int i = 1; i < 10; i++) { // �ִ� ���ϱ�
        nmax = max(nmax, arr[i]);
    }
    cout << nmax << endl;

    int index = 0;
    for (int i = 1; i < 10; i++) { // ���� 
        if (nmax == arr[i]) { index = i; }
    }
    cout << index;


    return 0;
}
