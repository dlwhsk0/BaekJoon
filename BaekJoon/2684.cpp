#include <iostream>
#include <string>
using namespace std;

/*
��H: 1 ��T: 0
��� ��츦 if������... ���� Ž��..?
TTT TTH THT THH HTT HTH HHT HHH
�ð� ���⵵: T(p) = p *(8 + (38 * 4) + 8) => O(n) ?
*/

int arr[8];

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int p, i, j;
    string coin;
    cin >> p;

    for(i = 0; i < p; i++) {
        for (j = 0; j < 8; j++) { arr[j] = 0; }
        cin >> coin;

        for (j = 0; j < 38; j++) {
            if (coin[j] == 'T') {
                if (coin[j + 1] == 'T') {
                    if (coin[j + 2] == 'T') { arr[0]++; }
                    else { arr[1]++; }
                }
                else {
                    if(coin[j + 2] == 'T') { arr[2]++; }
                    else { arr[3]++; }
                }
            }
            else { // coin[j] = 'H'
                if (coin[j + 1] == 'T') {
                    if (coin[j + 2] == 'T') { arr[4]++; }
                    else { arr[5]++; }
                }
                else {
                    if (coin[j + 2] == 'T') { arr[6]++; }
                    else { arr[7]++; }
                }
            }
        }

        for (j = 0; j < 8; j++) { cout << arr[j] << " "; }
        cout << '\n';
    }

    return 0;
}