#include <iostream>
using namespace std;

int n, m;

char arr[50][50];
int visit[50][50];

bool answer = false;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void Input();
bool dfs(int y, int x, int cnt);

bool IsInBoundary(int ny, int nx);

int main() {

	Input();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visit[i][j] != 0) continue;

			if (dfs(i, j, 1))
				answer = true;
		}
	}

	cout << (answer ? "Yes" : "No") << endl;

	return 0;
}

void Input()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
}

// check: n_visit >= visit + 4
//		
bool dfs(int y, int x, int cnt)
{
	visit[y][x] = cnt;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (IsInBoundary(ny, nx)) {
			if (visit[ny][nx] == 0) continue;
			if (arr[ny][nx] == arr[y][x] && abs(visit[ny][nx] - visit[y][x]) >= 3) {
				// Cycle!
				return true;
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (IsInBoundary(ny, nx)) {
			if (arr[ny][nx] == arr[y][x] && visit[ny][nx] == 0) {

				if (dfs(ny, nx, cnt + 1))
					return true;
			}
		}
	}

	return false;
}

bool IsInBoundary(int ny, int nx)
{
	if (ny >= 0 && ny < n && nx >= 0 && nx < m)
		return true;
	return false;
}
