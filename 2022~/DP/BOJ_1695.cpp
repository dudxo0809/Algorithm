#include <iostream>
#include <vector>
using namespace std;

int n, temp;
vector<int> v;

int dp[5000][5000];

//
// if(v[i] == v[j])
//		i++; j--;
// else
//		dp[i][j] = min(dp[i][j-1], dp[i+1][j]) + 1;


int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	for (int i = 0; i < n; i++) {
		dp[i][i] = 0;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= n - i; j++) {
			if (v[j] == v[j + i - 1])
				dp[j][j + i - 1] = dp[j + 1][j + i - 2];
			else
				dp[j][j + i - 1] = min(dp[j][j + i - 2], dp[j + 1][j + i - 1]) + 1;
		}
	}



	cout << dp[0][n - 1] << endl;

	return 0;
}