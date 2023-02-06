#include <iostream>
#include <vector>
using namespace std;

#define MAX_LEN		1024

int n, m;

int dp[MAX_LEN + 1][MAX_LEN + 1] = { 0, };


vector<int> ans;


void Input();

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);


	Input();;

	for (int i = 0; i < m; i++) {
		int x[2];
		int y[2];
		cin >> y[0] >> x[0] >> y[1] >> x[1];

		// 2234 -> 4,3 - 1,3 - 4,1 + 1,1
		ans.push_back(dp[y[1]][x[1]]
			- dp[y[0] - 1][x[1]]
			- dp[y[1]][x[0] - 1]
			+ dp[y[0] - 1][x[0] - 1]);
	}

	for (auto i : ans)
		cout << i << '\n';


	return 0;
}

void Input() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> dp[i][j];
			dp[i][j] = dp[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}
}