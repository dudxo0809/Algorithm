#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> v;
vector<int> dp;

void Input();
void Sort();
bool Pred(pair<int, int> a, pair<int, int> b);
int DP();

int main() {

	Input();
	Sort();

	cout << DP() << endl;

	return 0;
}

void Input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
		dp.push_back(1);
	}
}

void Sort() {
	sort(v.begin(), v.end(), Pred);
}

bool Pred(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int DP() {
	int ret = 0;
	for (int i = 0; i < v.size(); i++) {
		int max_dp = 0;
		for (int j = 0; j < i; j++) {
			if (v[j].second < v[i].second) {
				if (dp[j] > max_dp)
					max_dp = dp[j];
			}
		}
		dp[i] = max_dp + 1;
		if (dp[i] > ret)
			ret = dp[i];
	}

	return n - ret;
}