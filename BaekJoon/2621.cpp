#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

/*
1. ���ڸ� ������������ ����
2. ���ӵ� �������� �˻�
3. �� ���� �˻�
4. ������ ���� �˻�
*/

vector<pair<int, char>> v; // ī�� ����
int arr[10]; // ���� ���� ���� ����

int main() {

    int i, j, num, score;
    char color;
    bool cont = 1, same = 1;

    for (i = 0; i < 5; i++) { // �Է� �ޱ�
        cin >> color >> num;
        v.push_back({ num, color });
        arr[num]++;
    }

    sort(v.begin(), v.end()); // ���� �������� ����

    // ���� ���� �˻�
    for (i = 0; i < 5; i++) {
        if (i == 0) { num = v[i].first; continue; }
        if (v[i].first != ++num) { cont = 0; break; }
    }
    if (cont) { // ���ڰ� ��� ����: ��� ���� ������ �˻�
        for (i = 0; i < 5; i++) {
            if (i == 0) { color = v[i].second; continue; }
            if (v[i].second != color) { same = 0; break; }
        }
        if (same) { cout << v[4].first + 900; return 0; }
        else { cout << v[4].first + 500; return 0; }
    }

    // �� ���� ���� �˻�
    same = 1;
    for (i = 0; i < 5; i++) {
        if (i == 0) { color = v[i].second; continue; }
        if (v[i].second != color) { same = 0; break; }
    }
    if (same) { cout << v[4].first + 600; return 0; }

    // ���� ���� ã��
    int two = -1, twocntmax = 0, three = -1, four = -1;
    for (i = 1; i < 10; i++) {
        if (arr[i] == 2) {
            twocntmax++;
            if (twocntmax == 2) { twocntmax = max(i, two); }
            else { two = i; }
        }
        else if (arr[i] == 3) { three = i; }
        else if (arr[i] == 4) { four = i; }
    }
    if (four != -1) { score = four + 800; }
    else if (three != -1) {
        if (two != -1) { score = (three * 10) + two + 700; }
        else { score = three + 400; }
    }
    else if (two != -1) {
        if (twocntmax > 1) { score = (twocntmax * 10) + two + 300; }
        else { score = two + 200; }
    }
    else { score = v[4].first + 100; }

    cout << score;

    return 0;
}
