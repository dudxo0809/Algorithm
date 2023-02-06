#include <iostream>
using namespace std;


int dx[3] = { 1,1,1 };
int dy[3] = { -1,0,1 };

int n, m;

int cnt = 0;

char arr[10000][500];
bool visit[10000][500] = { false, };

void Input();
bool dfs(int x, int y);

int main() {

	Input();

	for (int i = 0; i < n; i++) {
		dfs(0, i);
	}


	cout << cnt << endl;

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

bool dfs(int x, int y)
{
	visit[y][x] = true;
	if (x == m - 1) {
		cnt++;
		return true;
	}


	for (int i = 0; i < 3; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];


		if (ny >= 0 && ny < n && nx >= 0 && nx <= m) {
			if (arr[ny][nx] != 'x' && !visit[ny][nx]) {

				if (dfs(nx, ny))
					return true;

			}
		}

	}

	return false;
}
