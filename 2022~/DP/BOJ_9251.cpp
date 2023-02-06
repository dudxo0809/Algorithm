#include <iostream>
using namespace std;

string a, b;

// dp[i][j] : a는 i까지, b는 j까지 탐색했을 때의 LCS길이
//
// 0 1 1 1 1 1
// 1 1 1 2 2 2	// a[i] == b[j] 이면 dp[i][j] = dp[i-1][j-1] + 1;
// 1 2 2 2 3 3	// 아니면 dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
// 1 
// 1
// 1

// idx==1 부터, 

int dp[1000][1000] = { 0, };


int main() {

	cin >> a >> b;
	// a.length => i indexing
	// b.length => j indexing


	dp[0][0] = (a[0] == b[0] ? 1 : 0);
	bool check = false;
	for (int i = 1; i < a.length(); i++) {
		if (check || dp[0][0] == 1) {
			dp[i][0] = 1;
		}
		else if (a[i] == b[0]) {
			check = true;
			dp[i][0] = 1;
		}
	}
	check = false;
	for (int j = 1; j < b.length(); j++) {
		if (check || dp[0][0] == 1) {
			dp[0][j] = 1;
		}
		else if (b[j] == a[0]) {
			check = true;
			dp[0][j] = 1;
		}
	}

	for (int i = 1; i < a.length(); i++) {
		for (int j = 1; j < b.length(); j++) {
			if (a[i] == b[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}


	cout << dp[a.length() - 1][b.length() - 1] << endl;

	return 0;
}