#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[1000];
int dp[1000];

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i < n; i++) {
		dp[i] = 9999;
	}
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		int step = arr[i];
		for (int j = 1; j <= step; j++) {
			if (i + j >= n) dp[n - 1] = min(dp[n - 1], dp[i] + 1);
			else dp[i + j] = min(dp[i + j], dp[i] + 1);
		}
	}
	if (dp[n - 1] >= 9999) cout << -1;
	else cout << dp[n - 1];
	return 0;
}
