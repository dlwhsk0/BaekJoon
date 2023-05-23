#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int x[4] = { 0,1,0,-1 };
int y[4] = { -1,0,1,0 };

int main() {
	int test;
	string str;
	cin >> test;

	for (int t = 0; t < test; t++) {
		cin >> str;

		int cx = 0, cy = 0, cd = 0;
		int minX = 0, maxX = 0, minY = 0, maxY = 0;

		for (int i = 0; i < str.size(); i++) {
			char c = str[i];

			if (c == 'L' || c == 'R') {
				if (c == 'L')
					cd = (cd + 3) % 4;
				else
					cd = (cd + 1) % 4;
			}

			else {
				if (c == 'F') {
					cx += x[cd];
					cy += y[cd];
				}
				else {
					cx -= x[cd];
					cy -= y[cd];
				}
				maxX = max(cx, maxX);
				maxY = max(cy, maxY);
				minX = min(cx, minX);
				minY = min(cy, minY);
			}
		}
		cout << (maxX - minX) * (maxY - minY) << '\n';
	}
	return 0;
}