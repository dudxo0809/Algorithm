#include <iostream>
using namespace std;


string a, b;
short dp[4001][4001];

short ret = 0;

int main() {

	cin >> a >> b;

	for (int i = 0; i <= 4000; i++)
		dp[i][0] = 0;
	for (int j = 1; j <= 4000; j++)
		dp[0][j] = 0;

	for (int i = 1; i <= a.length(); i++) {
		for (int j = 1; j <= b.length(); j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				ret = max(ret, dp[i][j]);
			}
		}
	}
	cout << ret << endl;

	return 0;
}