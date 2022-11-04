#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Pred(pair<int, int> a, pair<int, int> b) {	// idx, cnt
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int r, c, k;

int n_row = 3;
int n_column = 3;

int arr[101][101];


void Input();
void Simulation();

void R();
void C();

int main() {

	Input();

	Simulation();

	return 0;
}

void Input()
{
	cin >> r >> c >> k;

	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> arr[i][j];
		}
	}

	n_row = 3;
	n_column = 3;
}

void Simulation()
{
	int time_cnt = 0;

	for (int i = 0; i <= 100; i++) {
		if (arr[r][c] == k)
			break;

		time_cnt++;

		if (n_row >= n_column) {
			R();
		}
		else {
			C();
		}
	}

	if (time_cnt > 100 && arr[r][k] != k)
		cout << -1 << endl;
	else
		cout << time_cnt << endl;
}

void R()
{
	vector<vector<int>> temp(n_row + 1);
	vector<int> temp_len(n_row + 1);

	for (int i = 1; i <= n_row; i++) {
		vector<pair<int, int>> v(101);	// (idx, cnt)
		for (int j = 1; j <= n_column; j++) {
			if (arr[i][j] == 0)
				continue;
			v[arr[i][j]].first = arr[i][j]; // idx
			v[arr[i][j]].second++;			// cnt

		}

		sort(v.begin(), v.end(), Pred);

		for (auto& iter : v) {
			if (iter.second == 0)
				continue;
			temp[i].push_back(iter.first);
			temp[i].push_back(iter.second);
		}
		if (temp[i].size() > n_column)
			n_column = temp[i].size();

		temp_len[i] = temp[i].size();
	}
	for (int i = 1; i <= n_row; i++) {
		for (int j = 1; j <= n_column; j++) {
			arr[i][j] = 0;
		}
	}
	for (int i = 1; i <= n_row; i++) {
		for (int j = 1; j <= temp_len[i]; j++) {
			arr[i][j] = temp[i][j - 1];
		}
	}

}

void C()
{
	vector<vector<int>> temp(n_column + 1);
	vector<int> temp_len(n_column + 1);

	for (int i = 1; i <= n_column; i++) {
		vector<pair<int, int>> v(101);	// (idx, cnt)
		for (int j = 1; j <= n_row; j++) {
			if (arr[j][i] == 0)
				continue;
			v[arr[j][i]].first = arr[j][i]; // idx
			v[arr[j][i]].second++;			// cnt

		}

		sort(v.begin(), v.end(), Pred);

		for (auto iter : v) {
			if (iter.second == 0)
				continue;
			temp[i].push_back(iter.first);
			temp[i].push_back(iter.second);
		}
		if (temp[i].size() > n_row)
			n_row = temp[i].size();

		temp_len[i] = temp[i].size();
	}

	for (int i = 1; i <= n_row; i++) {
		for (int j = 1; j <= n_column; j++) {
			arr[i][j] = 0;
		}
	}
	for (int i = 1; i <= n_column; i++) {
		for (int j = 1; j <= temp_len[i]; j++) {
			arr[j][i] = temp[i][j - 1];
		}
	}

}
