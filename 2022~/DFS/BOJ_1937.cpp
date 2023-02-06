
#include <iostream>
using namespace std;

/*

*/

int n;
int arr[500][500];
int cnt[500][500];
int visit[500][500];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void Input();
void Solve();

int Dfs(int _y, int _x);


int main() {

	Input();

	Solve();

	return 0;
}

void Input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cnt[i][j] = 1;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			visit[i][j] = 0;
}

void Solve()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == 0)
				cnt[i][j] = Dfs(i, j);
		}
	}

	int answer = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			answer = max(cnt[i][j], answer);
		}
	}

	cout << answer << endl;
}

int Dfs(int _y, int _x)
{
	int ret = cnt[_y][_x];

	visit[_y][_x] = 1;

	int maxval_dir = 0;

	for (int i = 0; i < 4; i++) {
		int ny = _y + dy[i];
		int nx = _x + dx[i];
		if (ny >= 0 && ny < n && nx >= 0 && nx < n) {
			if (arr[_y][_x] < arr[ny][nx]) {
				if (visit[ny][nx] == 1) {
					// Read cnt array 
					maxval_dir = max(maxval_dir, cnt[ny][nx]);
				}
				else {
					// DFS
					cnt[ny][nx] = Dfs(ny, nx);
					maxval_dir = max(maxval_dir, cnt[ny][nx]);
				}
			}
		}
	}
	ret += maxval_dir;

	return ret;
}
