#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// ��� ����� ���� �˻��ϸ鼭 �ִ��� ���
// ��Ʈ��ŷ�̶�? (= �𰢰˻�) �ظ� ã�� ���� �ذ� �ƴϸ� �ǵ��ư��� �ٽ� ã�� ���

int n, num, ans = 0;
vector<int> v;

void dfs(int sum) {
    int add, tmp;

    if (v.size() == 2) { // ù��°�� �������� ���� ��� : Ž�� ��
        ans = max(ans, sum); // �ִ� �ֱ�
        return;
    }

    for (int i = 1; i < v.size() - 1; i++) {
        add = v[i - 1] * v[i + 1]; // ��
        tmp = v[i]; // ������ ���� ����

        v.erase(v.begin() + i); // i��° ���� ����
        dfs(sum + add); // ���� ���� Ž��
        v.insert(v.begin() + i, tmp); // �ǵ����ִ� �۾� : ��Ʈ��ŷ ����
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> n;
    
    for (int i = 0; i < n; i++) { // �Է�
        cin >> num;
        v.push_back(num);
    }

    dfs(0);
    cout << ans;

    return 0;
}