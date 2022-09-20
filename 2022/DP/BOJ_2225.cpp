#include <iostream>
using namespace std;

int n, k;
int dp[201][201] = { 0, };

// i���� j�� ������
// 1���� n�� : 1
// n���� 0�� : 1
// n���� 1�� : n

// i���� j�� : dp[i-1][j] ~ dp[i-1][0]  sum

int main() {

	cin >> n >> k;

	for (int i = 0; i <= n; i++)
		dp[1][i] = 1;
	for (int i = 0; i <= k; i++)
		dp[i][0] = 1;
	for (int i = 1; i <= k; i++)
		dp[i][1] = i;

	for (int i = 2; i <= k; i++) {
		for (int j = 2; j <= n; j++) {
			for (int r = 0; r <= j; r++) {
				dp[i][j] += dp[i - 1][r];
				dp[i][j] %= 1000000000;
			}

		}
	}



	cout << dp[k][n] << endl;

	return 0;
}

