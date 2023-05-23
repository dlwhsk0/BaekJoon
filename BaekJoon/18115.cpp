#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, x;
    int input;
    vector<int> v;
    deque<int> dq;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }

    input = 1;

    reverse(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        if (v[i] == 1) {
            dq.push_back(input);
        }
        else if (v[i] == 2) {
            int temp = dq[dq.size() - 1];
            dq.pop_back();
            dq.push_back(input);
            dq.push_back(temp);
        }
        else if (v[i] == 3) {
            dq.push_front(input);
        }
        input++;
    }

    while (!dq.empty()) {
        cout << dq[dq.size() - 1] << ' ';
        dq.pop_back();
    }
}