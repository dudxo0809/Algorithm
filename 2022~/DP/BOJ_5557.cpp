#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[100];
long long int dp[100][21];

// dp[i][j] : i번째 자리에서 숫자 j를 만들 수 있는 경우의 수


int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dp[0][arr[0]] = 1;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= 20; j++) {
			if (dp[i - 1][j] != 0) {
				if (j - arr[i] >= 0)
					dp[i][j - arr[i]] += dp[i - 1][j];
				if (j + arr[i] <= 20)
					dp[i][j + arr[i]] += dp[i - 1][j];
			}
		}
	}
	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= 20; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	*/
	cout << dp[n - 2][arr[n - 1]] << endl;


	return 0;
}