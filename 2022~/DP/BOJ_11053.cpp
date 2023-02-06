#include <iostream>
using namespace std;

int n;

int arr[1000];
int dp[1000] = { 0, };


int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}

	// 1 2 1 3 2 4
	for (int i = 0; i < n; i++) {
		int max_dp = 0;
		for (int j = 0; j < i; j++) {
			// 순회하면서 자신보다 작은값이 없다면 dp는 1
			// 자기보다 값이 작으면서 dp가 가장 큰거 + 1 => dp
			if (arr[j] < arr[i]) {
				if (dp[j] > max_dp)
					max_dp = dp[j];
			}
		}
		dp[i] = max_dp + 1;
	}

	int _max = 0;
	for (int i = 0; i < n; i++) {
		if (dp[i] > _max)
			_max = dp[i];
	}
	cout << _max << endl;

	return 0;
}