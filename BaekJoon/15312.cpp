#include <iostream>
#include <string>
using namespace std;

int name[4000];
int arr[26] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int size, answer, i, j;
    string name1, name2;
    cin >> name1;
    cin >> name2;

    size = name1.length() * 2;
    for (i = 0, j = 0; i < size; i += 2, j++) {
        name[i] = arr[name1[j] - 'A'];
        name[i + 1] = arr[name2[j] - 'A'];
    }

    for (; size >= 3; size--) {
        for (i = 0; i < size - 1; i++) { name[i] = (name[i] + name[i + 1]) % 10; }
    }
    answer = name[0] * 10 + name[1];
    if (answer < 10) { cout << 0 << answer; }
    else { cout << answer; }

    return 0;
}