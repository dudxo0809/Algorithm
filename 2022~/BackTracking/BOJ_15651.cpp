#include<iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;

void dfs(int cnt);

int main() {

	cin >> n >> m;

	dfs(0);

	return 0;
}

void dfs(int cnt) {
	if (cnt == m) {
		for (auto i : v)
			cout << i << " ";
		cout << endl;
	}
	else {
		int start_idx = (v.empty() ? 0 : v.back() - 1);
		for (int i = start_idx; i < n; i++) {
			v.push_back(i + 1);
			dfs(cnt + 1);
			v.pop_back();
		}
	}
}