#include <iostream>
#include <algorithm>
using namespace std;


int n, m;
int arr[50001];
int dp[4][50001]; // i���� ������ ���� ��, j��° ĭ���� Ȯ������ ��
// �ִ� ĭ�� ����

int main() {

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	cin >> m;

	for (int i = 1; i <= 3; i++) {
		for (int j = 1 * m; j <= n; j++) {
			dp[i][j] = max(dp[i - 1][j - m] + arr[j] - arr[j - m], dp[i][j - 1]);
		}
	}
	cout << dp[3][n] << endl;

	return 0;
}