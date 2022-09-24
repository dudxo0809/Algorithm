#include <iostream>
#include <vector>
using namespace std;

int n, m;

vector<int> v;
bool dp[2001][2001]; // 4M

// dp[i][j] : i 부터 j 까지의 수열에서 펠린드롬인가?
//
// if(v[j] != dp[i][j-1])
//	  dp[i][j] = 
// dp[i][j] = 
//

bool IsPalindrom(int s, int e) {
	if (v[s] == v[e] && dp[s + 1][e - 1] == true)
		return true;
	else
		return false;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	for (int i = 0; i < n - 1; i++) {
		dp[i][i] = true;
		if (v[i] == v[i + 1])
			dp[i][i + 1] = true;
	}
	dp[n - 1][n - 1] = true;

	for (int i = n - 1; i >= 0; i--) {
		for (int j = i + 2; j < n; j++) {
			if (IsPalindrom(i, j))
				dp[i][j] = true;
			else
				dp[i][j] = false;
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;

		cout << (dp[s - 1][e - 1] ? 1 : 0) << "\n";

	}

	return 0;
}