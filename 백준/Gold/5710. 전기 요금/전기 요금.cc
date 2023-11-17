#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#define ll long long
using namespace std;

int a, b, awh;

int getPrice(int wh) {
	if (wh < 100) { return wh * 2;	}
	else if (wh < 10000) { return 200 + (wh - 100) * 3;	}
	else if (wh < 1000000) { return 29900 + (wh - 10000) * 5; }
	else { return 4979900 + (wh - 1000000) * 7;	}
}

int getWh(int price) {
	int wh = 0;
	wh += min(price, 200) / 2;
	price -= 200;
	if (price > 0) {
		wh += min(price, 29700) / 3;
		price -= 29700;
		if (price > 0) {
			wh += min(price, 4950000) / 5;
			price -= 990000 * 5;
			if (price > 0) { wh += price / 7; }
		}
	}
	return wh;
}

int bsearch(int l, int r) {
	int mid = (l + r) / 2;
	int sg = getPrice(mid);
	int neigh = getPrice(awh - mid);

	if (neigh - sg == b) { return sg; }
	if (l == r) { return 0; }
	if (neigh - sg > b) { return bsearch(mid + 1, r); }
	else { return bsearch(l, mid - 1); }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	while (1) {
		cin >> a >> b;
		if (a == b && a == 0) { return 0; }
		awh = getWh(a);
		cout << bsearch(0, awh) << endl;
	}

    return 0;
}