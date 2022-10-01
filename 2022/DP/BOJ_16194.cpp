#include<iostream>
using namespace std;

int n;
int arr[1001];
int dp[1001]; // i+1 장 최소 금액
//
int main() {

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	dp[0] = 0;
	dp[1] = arr[1];
	for (int i = 2; i <= n; i++) {
		int _min = arr[i];
		for (int j = 1; j <= i / 2; j++) {
			if (_min > (dp[j] + dp[i - j]))
				_min = dp[j] + dp[i - j];
		}
		dp[i] = _min;
	}


	cout << dp[n] << endl;


	return 0;
}