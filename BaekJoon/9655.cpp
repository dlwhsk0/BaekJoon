#include <string>
#include <iostream>

using namespace std;

// ���� 1�� �Ǵ� 3��, ������ ���� �������� ����� ������ �̱�� �ȴ�
// Ȧ���� ���, ¦���� â��

int main()
{
    int n;
    string sk = "SK";
    string cy = "CY";

    cin >> n;

    if (n % 2) { cout << sk; }
    else { cout << cy; }

    return 0;
}