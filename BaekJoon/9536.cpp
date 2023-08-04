#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string> // getline : 원하는 구분자(delimiter)를 만날 때 까지 모든 문자열을 입력 받아 하나의 string 객체에 저장
using namespace std;

// 버퍼를 비우는 것이 중요한 문제...

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    int t, i, j; // 테스트 케이스
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