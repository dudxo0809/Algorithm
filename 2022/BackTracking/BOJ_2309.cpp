#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, bool>> v(9);
int sum = 0;

bool Pred(pair<int, bool> a, pair<int, bool> b) { return a.first < b.first; }

bool dfs(int cnt) {
	if (cnt == 7) {
		if (sum == 100)
			return true;
		else
			return false;
	}
	else {
		for (int i = 0; i < 9; i++) {
			if (v[i].second == false) {

				v[i].second = true;
				sum += v[i].first;

				if (dfs(cnt + 1))
					return true;

				v[i].second = false;
				sum -= v[i].first;
			}
		}
	}
	return false;
}

int main() {

	for (int i = 0; i < 9; i++) {
		int temp;
		cin >> temp;
		v[i] = { temp, false };
	}

	dfs(0);

	sort(v.begin(), v.end(), Pred);

	for (auto i : v) {
		if (i.second == true)
			cout << i.first << endl;
	}

	return 0;
}