#include <iostream>
#include <algorithm>
using namespace std;

/* header <algorithm>
template <class T>
const T& min (const T& a, const T& b)

template�̶�, �Լ��� Ŭ������ ���������� �ٽ� �ۼ����� �ʾƵ�,
���� �ڷ� ������ ����� �� �ֵ��� �ϰ� ����� ���� Ʋ�̴�. */

int main() {
    int x, y, w, h, result;
    scanf("%d %d %d %d", &x, &y, &w, &h);

    result = min((h - y), min((w - x), min(x, y)));
    cout << result;


    return 0;
}