#include <iostream>
#include <string>

using namespace std;

/*
학생 수 n, 평균
1. 평균 구하기 avg
2. 평균 넘는 학생 수 구하기 count
3. 비율 구하기

cout << fixed; 소수점을 고정시켜 표현하겠다.
cout.precision(6); 6자리까지 표현하겠다.

*/

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int arr[1000] = { 0 };
	int test, t, student, s;
	float avg, count;

	cin >> test;
	for (t = 0; t < test; t++) {
		cin >> student;
		avg = 0; count = 0;

		for (s = 0; s < student; s++) {
			cin >> arr[s];
			avg += arr[s];
		}
		avg /= student; // 평균 구하기

		for (s = 0; s < student; s++) {
			if (avg < arr[s]) { count++; }
		}
		count = count / student * 100; // 비율 구하기

		cout << fixed;
		cout.precision(3); // 소수점 셋째 자리
		cout << count << "%" << endl;
	}

	return 0;
}
