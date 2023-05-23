#include <iostream>
using namespace std;

int main() {
    /*cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);*/

    int i, n, t, m, s, t1=0, t2=0, last, now, team1=0, team2=0;

    cin >> n;
    
    for (i = 0; i < n; i++) {
        scanf_s("%d %d:%d", &t, &m, &s);
        now = m * 60 + s;
        //cout << "*now = " << now/60 << ":" << now%60 << '\n';

        if (i != 0) {
            if (t1 > t2) { team1 += now - last; }
            else if (t1 < t2) { team2 += now - last; }
            //printf("**team1 = %02d:%02d\n", (team1 / 60), (team1 % 60));
            //printf("**team2 = %02d:%02d\n", (team2 / 60), (team2 % 60));
        }
        last = now;
        //cout << "*last = " << last/60 << ":" << last%60 << '\n';

        if (t == 1) { t1++; }
        else { t2++; }

        if (i == n-1) {
            if (t1 > t2) { team1 += 48*60 - last; }
            else if (t1 < t2) { team2 += 48*60 - last; }
            //printf("**team1 = %02d:%02d\n", (team1 / 60), (team1 % 60));
            //printf("**team2 = %02d:%02d\n", (team2 / 60), (team2 % 60));
        }
    }

    printf("%02d:%02d\n", (team1 / 60), (team1 % 60));
    printf("%02d:%02d", (team2 / 60), (team2 % 60));

    return 0;
}
