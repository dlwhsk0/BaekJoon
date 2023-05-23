#include <iostream>
#include <string>
#include <set>
using namespace std;

/*
string str, temp, ans;
str: ���� ���ڿ�
temp: �� D-���� ��� ������ ���ڿ�
ans: D-������ �˻��ϱ� ���� �ֵ��� ������ ���ڿ�
*/

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, i, j;
    string str, temp="", ans;
    bool check = 1; 

    while (1) {
        check = 1;
        cin >> str;
        if (str == "*") { return 0; }

        n = str.length();
        if (n == 1) { check = 1; }
        else {
            for (i = 0; i <= n - 2; i++) { // 0�� ���� n-2�� ����
                //cout << "\n***" << i << "***" << '\n';
                ans.clear();
                check = 1
                for (j = 0; j < n-i-1; j++) {
                    temp.clear();
                    temp += str[j];
                    temp += str[j + i + 1];
                    //cout << "*Temp = " << temp << '\n';

                    if (ans.find(temp) != string::npos) { // �ߺ� ����
                        check = 0;
                        break;
                    }
                    else {
                        ans += temp;
                        ans += "/"; // ������ ���� �����ø� �־���
                    }
                    //cout << "**ans = " << ans << '\n';
                }
            }
        }

        if (check) { cout << str << " is surprising.\n"; }
        else { cout << str << " is NOT surprising.\n"; }
    }

    return 0;
}
