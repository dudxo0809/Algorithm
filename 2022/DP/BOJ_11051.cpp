// ÆÄ½ºÄ®ÀÇ »ï°¢Çü?
// [n, k] = [n - 1, k] + [n - 1, k - 1];

#include <iostream>
using namespace std;

int n, k;
int dp[1001][1001] = { 0, };

int main() {

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j == 0 || i == j)
				dp[i][j] = 1;
			else
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];

			dp[i][j] %= 10007;
		}
	}

	cout << dp[n][k] << endl;


	return 0;
}