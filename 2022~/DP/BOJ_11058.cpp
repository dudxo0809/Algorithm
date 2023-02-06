#include <iostream>
using namespace std;


long long int n;
long long int dp[101];

/*

dp[i] = dp[i-1] + 1 or 2*dp[i-3]
					   3*dp[i-4]
					   4*dp[i-5]
					   j*dp[i-j-1]

*/

int main() {

	cin >> n;

	for (int i = 1; i <= n; i++) {

		dp[i] = max(dp[i], dp[i - 1] + 1);
		for (int j = 2; j <= i - 1; j++) {
			dp[i] = max(dp[i], j * dp[i - j - 1]);
		}
	}

	cout << dp[n] << endl;

	return 0;
}