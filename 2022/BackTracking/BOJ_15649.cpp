#include <iostream>
#include <vector>
using namespace std;

int n, m;

vector<int> v;
bool visit[8] = { false, };

void dfs(int cnt) {

	if (cnt == m) {
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << endl;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (visit[i] == false) {
				visit[i] = true;
				v.push_back(i + 1);
				dfs(cnt + 1);
				visit[i] = false;
				v.pop_back();
			}
		}
	}
}
/*
(8, 4)
   1 2

*/

int main() {

	cin >> n >> m;

	dfs(0);

	return 0;
}