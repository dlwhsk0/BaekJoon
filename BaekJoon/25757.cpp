#include <iostream>
#include <map>

using namespace std;

/*
<queue> ť�� Ž���� �Ұ���

map�� ���? - �ߺ� ���� �ٵ� value ���� ��� �̿�?
*/

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int num, g, i, count;
    string temp;
    char game; // y�� 2, f�� 3, O�� 4��
    cin >> num >> game;

    if (game == 'Y') { g = 1; }
    else if (game == 'F') { g = 2; }
    else if (game == 'O') { g = 3; }

    map<string, int> name;
    for (i = 0; i < num; i++) { // ���� ����
        cin >> temp;
        name[temp] = 0;
    }

    count = name.size() / g;
    cout << count;

    return 0;
}
