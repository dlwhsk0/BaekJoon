#include <iostream>
#include <map>

using namespace std;

/*
<queue> 큐는 탐색이 불가능

map을 사용? - 중복 제외 근데 value 값을 어떻게 이용?
*/

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int num, g, i, count;
    string temp;
    char game; // y는 2, f는 3, O는 4명
    cin >> num >> game;

    if (game == 'Y') { g = 1; }
    else if (game == 'F') { g = 2; }
    else if (game == 'O') { g = 3; }

    map<string, int> name;
    for (i = 0; i < num; i++) { // 정보 삽입
        cin >> temp;
        name[temp] = 0;
    }

    count = name.size() / g;
    cout << count;

    return 0;
}
