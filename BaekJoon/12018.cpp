#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

/*
1) 마지노선의 숫자를 저장
그거보다 같거나 많기만 하면 됨
mile배열에 전부 저장한 후 내림차순 정렬하고 마지막 순서를 sub배열에 저장
*신청 수가 수강인원보다 적다면 1점으로 신청 가능
sub배열에 1 저장

2) 최대로 들을 수 있는 과목 개수 구하기
sub배열을 오름차순으로 정렬하고
마일리지를 빼가면서 신청가능한 과목 개수 구하기
*/

int sub[100];
int mile[100];

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m, i, num, limit, j, count = 0;
    cin >> n >> m; // 과목 수, 주어진 마일리지

    for (i = 0; i < n; i++) {
        cin >> num >> limit; // 신청 수, 수강인원
        for (j = 0; j < num; j++) { cin >> mile[j]; }

        if (num < limit) { sub[i] = 1; continue; }

        sort(mile, mile + num, greater<int>()); // 내림차순
        sub[i] = mile[limit - 1];
    }

    sort(sub, sub + n); // 오름차순

    for (i = 0; i < n; i++) {
        count++; m -= sub[i];
        if (m < 0) { count--; break; }
    }
    cout << count;

    return 0;
}