#include <iostream>
#include <algorithm>
using namespace std;

/* header <algorithm>
template <class T>
const T& min (const T& a, const T& b)

template이란, 함수나 클래스를 개별적으로 다시 작성하지 않아도,
여러 자료 형으로 사용할 수 있도록 하게 만들어 놓은 틀이다. */

int main() {
    int x, y, w, h, result;
    scanf("%d %d %d %d", &x, &y, &w, &h);

    result = min((h - y), min((w - x), min(x, y)));
    cout << result;


    return 0;
}