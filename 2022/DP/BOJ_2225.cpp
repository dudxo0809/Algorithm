#include <iostream>
using namespace std;

int n, k;
int dp[201][201] = { 0, };

// i개로 j원 가짓수
// 1개로 n원 : 1
// n개로 0원 : 1
// n개로 1원 : n

// i개로 j원 : dp[i-1][j] ~ dp[i-1][0]  sum

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

