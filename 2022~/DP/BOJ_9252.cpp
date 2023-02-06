#include <iostream>
#include <vector>
using namespace std;

string s1, s2;
int x, y;

vector<char> answer;

int dp[1001][1001] = { 0, };

int main() {

	cin >> s1 >> s2;
	for (int i = 1; i <= s1.length(); i++) {
		for (int j = 1; j <= s2.length(); j++) {
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}

	x = s2.length();
	y = s1.length();
	cout << dp[y][x] << endl;
	while (dp[y][x] != 0) {
		if (dp[y][x] == dp[y - 1][x])
			y--;
		else if (dp[y][x] == dp[y][x - 1])
			x--;
		else {
			answer.push_back(s1[y - 1]);
			x--; y--;
		}
	}

	for (auto i = answer.rbegin(); i != answer.rend(); ++i)
		cout << *i;

	return 0;
}