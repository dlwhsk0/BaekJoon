#include <iostream>
using namespace std;

int arr[5]; // 1~5
int select[5]; // 중복 조합

void DFS(int idx, int cnt) {
    if (cnt == 3) {
        cout << " { ";
        for (int i = 0; i < 3; i++) {
            cout << select[i] << " ";
        }
        cout << "}\n";
        return;
    }

    for (int i = idx; i < 5; i++) {
        select[cnt] = arr[i];
        DFS(i, cnt + 1);
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1;
    }
    DFS(0, 0);

    return 0;
}