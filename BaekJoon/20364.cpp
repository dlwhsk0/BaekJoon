#include <stack>
#include <iostream>

using namespace std;

bool check[1048577];

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, q, num, idx;
    bool reach;
    cin >> n >> q;

    for (int i = 0; i < q; i++) {
        cin >> num;
        idx = num;
        reach = 1; // 초기화
        stack<int> st; // 초기화

        while (idx != 0) {
            st.push(idx);
            idx /= 2;
        }

        while (!st.empty()) { // 경로 확인
            idx = st.top();

            if (check[idx]) { // 불가능
                cout << idx << '\n';
                reach = 0;
                break;
            }
            else { // 가능
                st.pop();
            }
        }

        if (reach) {
            cout << 0 << '\n';
            check[num] = 1;
        }
    }

    return 0;
}
