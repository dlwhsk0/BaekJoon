#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int name[4000];
int arr[26] = { 3, 2, 1, 2, 4, 3, 1, 3, 1, 1, 3, 1, 3, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m, minnum, maxnum, size, i, j, answer;
    bool flag;
    string n1, n2;

    cin >> n >> m;
    cin >> n1 >> n2;

    minnum = min(n, m);
    maxnum = max(n, m);

    for (i = 0; i < minnum; i++) {
        name[2 * i] = arr[n1[i]-'A'];
        name[2 * i + 1] = arr[n2[i]-'A'];
    }

    size = n + m;
    if (n != m) { // 길이가 다를 경우
        if (maxnum == n) { flag = 0; }
        else { flag = 1; }

        if (!flag) { // n1이 더 길다
            for (i = minnum * 2, j = minnum; i < size; i++, j++) { name[i] = arr[n1[j]-'A']; }
        }
        else {
            for (i = minnum * 2, j = minnum; i < size; i++, j++) { name[i] = arr[n2[j]-'A']; }
        }
    }

    for (; size > 2; size--) {
        for (i = 0; i < size; i++) { name[i] = (name[i] + name[i + 1]) % 10; }
    }
    answer = name[0] * 10 + name[1];
    cout << answer << "%";
    
    return 0;
}