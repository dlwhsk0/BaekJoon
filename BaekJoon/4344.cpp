#include <iostream>
#include <string>

using namespace std;

/*
�л� �� n, ���
1. ��� ���ϱ� avg
2. ��� �Ѵ� �л� �� ���ϱ� count
3. ���� ���ϱ�

cout << fixed; �Ҽ����� �������� ǥ���ϰڴ�.
cout.precision(6); 6�ڸ����� ǥ���ϰڴ�.

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
		avg /= student; // ��� ���ϱ�

		for (s = 0; s < student; s++) {
			if (avg < arr[s]) { count++; }
		}
		count = count / student * 100; // ���� ���ϱ�

		cout << fixed;
		cout.precision(3); // �Ҽ��� ��° �ڸ�
		cout << count << "%" << endl;
	}

	return 0;
}
