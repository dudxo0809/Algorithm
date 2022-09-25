#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t, n;
	string temp;

	vector<string> ans;

	cin >> t;
	for (int k = 0; k < t; k++) {
		cin >> n;

		vector<string> v;

		for (int j = 0; j < n; j++) {
			cin >> temp;
			v.push_back(temp);
		}
		sort(v.begin(), v.end());

		bool ex = false;
		for (int i = 0; i < n - 1; i++) {
			if (ex) // ex : 부분문자열?
				break;
			bool flag = true;
			for (int j = 0; j < v[i].size(); j++) {
				if (v[i][j] != v[i + 1][j]) {
					flag = false;
					break;
				}
			}
			if (flag)
				ex = true;

		}
		ans.push_back(ex ? "NO" : "YES");

	}

	for (auto i : ans)
		cout << i << '\n';



	return 0;
}