#include <iostream>

using namespace std;

/*
���������� for�� ������ Ǯ�� ���� �����ؾ� �� ���� �ִ�.
����� ����� ������ ���� ���� �Է¹ްų� ����� ��
�ð��ʰ��� �� �� �ִٴ� ���̴�.

C++�� ����ϰ� �ְ� cin/cout�� ����ϰ��� �Ѵٸ�,
cin.tie(NULL); ios_base::sync_with_stdio(false);
�� �� �� ������ �ְ�, endl ��� ���๮��(\n)�� ����.
��, �̷��� �ϸ� �� �̻� scanf/printf/puts/getchar/putchar ��
C�� ����� ����� ����ϸ� �� �ȴ�.
*/

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    int a, b, sum = 0;
    for (int i = 0; i < t; i++) {
        cin >> a >> b; // ���� a ���� b

        cout << a + b << '\n';
    }


    return 0;
}
