#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string> // getline : ���ϴ� ������(delimiter)�� ���� �� ���� ��� ���ڿ��� �Է� �޾� �ϳ��� string ��ü�� ����
using namespace std;

// ���۸� ���� ���� �߿��� ����...

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    int t, i, j; // �׽�Ʈ ���̽�
    cin >> t;
    cin.clear();

    string flush;
    getline(cin, flush);

    for (i = 0; i < t; i++) {
        string s, temp;
        getline(cin, s);
        map<string, bool> visited;
        while (1) {
            getline(cin, temp);
            string a;
            bool q = false;
            for (j = temp.length() - 1; j >= 0; j--) {
                if (temp[j] == ' ') {
                    reverse(a.begin(), a.end());
                    if (a == "say?") { q = true; break; }
                    visited[a] = true;
                    break;
                }
                else { a += temp[j]; }
            }

            if (q) { break; }
        }
        temp.clear();

        vector<string> res;
        for (j = 0; j < s.length(); j++) {
            if (s[j] == ' ') {
                if (!visited.count(temp)) { res.push_back(temp); }
                temp.clear();
            }
            else { temp += s[j]; }
        }

        if (!visited.count(temp)) { res.push_back(temp); }
        for (j = 0; j < res.size(); j++) { cout << res[j] << " "; }
        cout << '\n';
    }
    
    return 0;
}