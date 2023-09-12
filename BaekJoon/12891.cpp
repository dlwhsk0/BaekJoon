#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// ���ڿ��� p�� ������ŭ ������ �Űܰ��� �˻�
// �� ���� �˻簡 �ƴ϶� �ٲ� ���ĺ��� ��������

int rule[4];
int cnt, a, c, g, t;

void addCount(char i) {
    if (i == 'A') { a++; }
    else if (i == 'C') { c++; }
    else if (i == 'G') { g++; }
    else { t++; }
}

void minCount(char i) {
    if (i == 'A') { a--; }
    else if (i == 'C') { c--; }
    else if (i == 'G') { g--; }
    else { t--; }
}

void check() {
    if (a >= rule[0] && c >= rule[1] && g >= rule[2] && t >= rule[3]) { cnt++; }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int s, p;
    string str;

    cin >> s >> p; // �Է�
    cin >> str;
    for (int i = 0; i < 4; i++) { cin >> rule[i]; }

    for (int i = 0; i < p; i++) { addCount(str[i]); } // ó�� ��й�ȣ
    check();

    for (int i = p; i < s; i++) {
        minCount(str[i - p]); // ���� ���� ���ĺ� ���� ����
        addCount(str[i]); // ���� ���ĺ� ���� ����
        check();
    }
    cout << cnt;

    return 0;
}