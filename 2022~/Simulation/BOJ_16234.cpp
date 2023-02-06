#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
using namespace std;

int n, l, r;
int day = 0;

int arr[50][50];
int country_idx[50][50];
bool visit[50][50];

vector<pair<int, int>> Union_info; // (n_country, population)


int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };


void Input();

bool CanMove();
void MakeUnion();
void Init_Array();

int main() {

	Input();

	while (CanMove()) {

		day++;
		MakeUnion();

		Init_Array();
	}

	cout << day << endl;

	return 0;
}

void Input()
{
	cin >> n >> l >> r;
	int idx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			country_idx[i][j] = idx++;
		}
	}
}

bool CanMove()
{
	// Use BFS => Union numbering
	// 
	// Union has n_country, total population
	// // Union idx
	// 
	// if number != n^2 - 1 : return fasle;

	int idx = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j]) {

				idx++;

				Union_info.push_back(make_pair(1, arr[i][j]));
				country_idx[i][j] = idx;

				queue<pair<int, int>> q;
				q.push(make_pair(i, j));
				visit[i][j] = true;
				while (!q.empty()) {

					int x = q.front().second;
					int y = q.front().first;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (ny >= 0 && ny < n && nx >= 0 && nx < n) {
							if (visit[ny][nx] == false) {

								if (abs(arr[ny][nx] - arr[y][x]) >= l && abs(arr[ny][nx] - arr[y][x]) <= r) {
									q.push(make_pair(ny, nx));
									visit[ny][nx] = true;
									Union_info.back().first++;
									Union_info.back().second += arr[ny][nx];
									country_idx[ny][nx] = idx;
								}


							}
						}
					}
				}
			}
		}
	}

	if (Union_info.size() == n * n)
		return false;
	else
		return true;
}

void MakeUnion()
{
	// loop union
	// Substitute new idx to country_idx

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int n_country = Union_info[country_idx[i][j] - 1].first;
			int total_population = Union_info[country_idx[i][j] - 1].second;
			arr[i][j] = total_population / n_country;
		}
	}


}

void Init_Array()
{
	Union_info.clear();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visit[i][j] = false;

		}
	}
}
