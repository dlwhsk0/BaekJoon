#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#define ll long long
using namespace std;

// �����̵� ������ �˰���

int alphabet[26]; // ��ȣȭ�� ��й�ȣ ���ĺ� ī��Ʈ
int result[26]; // ���� ��й�ȣ�� ���ĺ� ī��Ʈ
int lenres, lenori;
string res, origin;

bool check() { // ���� ��й�ȣ�� �󵵼� ��
    bool ans = true;
    for (int i = 0; i < lenori; i++) {
        if (alphabet[((int)origin[i] - 'a')] != result[((int)origin[i] - 'a')]) { ans = false; break; }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    bool c;
    cin >> t;

    for (int k = 0; k < t; k++) {
        cin >> res;
        cin >> origin;

        lenres = res.length(); // �ʱ�ȭ
        lenori = origin.length();
        fill_n(alphabet, 26, 0);
        fill_n(result, 26, 0);
        c = false;

        for (int i = 0; i < lenori; i++) { // ��� ���� �� ù��° �� ����
            result[(int)(origin[i] - 'a')]++;
            alphabet[(int)(res[i] - 'a')]++;
        }
        if (check()) { c = true; }
        else {
            for (int i = lenori; i < lenres; i++) {
                alphabet[((int)res[i] - 'a')]++; // ���� ���ĺ� �� ����
                alphabet[((int)res[i - lenori] - 'a')]--; // ���� ���ĺ� �� �߰�
                
                if (check()) { c = true; break; }
            }
        }

        if (c) { cout << "YES" << '\n'; }
        else { cout << "NO" << '\n'; }
    }

    return 0;
}