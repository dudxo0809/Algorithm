#include <iostream>
#include <queue>
using namespace std;

int n, m;
int arr[300][300];
int visit[300][300];

int temp_arr[300][300];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int cnt = 1;
int day = 0;

void Melt(int y, int x) {
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (arr[ny][nx] == 0)
			temp_arr[y][x]--;
	}
	if (temp_arr[y][x] < 0)
		temp_arr[y][x] = 0;
}

void Clear() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			visit[i][j] = 0;
	cnt = 0;
}


void bfs(int _i, int _j) {
	cnt++;
	queue<pair<int, int>> q;

	q.push(make_pair(_i, _j));

	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx >= 0 && nx < m && ny >= 0 && ny < n)
				if (arr[ny][nx] != 0 && visit[ny][nx] == 0) {
					q.push(make_pair(ny, nx));
					visit[ny][nx] = 1;
					Melt(ny, nx);
				}
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = temp_arr[i][j];
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			temp_arr[i][j] = arr[i][j];
		}


	while (cnt < 2) {
		bool ch = false;
		day++;
		Clear();
		for (int i = 1; i < n; i++) {
			for (int j = 1; j < m; j++) {
				if (arr[i][j] != 0 && visit[i][j] == 0) {
					ch = true;
					bfs(i, j);
				}
			}
		}
		if (ch == false) {
			cout << 0 << endl;
			return 0;
		}
	}

	cout << day - 1 << endl;


	return 0;
}