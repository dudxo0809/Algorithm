// https://www.acmicpc.net/problem/14500


#include <iostream>
using namespace std;


int n, m;
int arr[500][500] = { 0, };
int visit[500][500] = { 0, };

int _max = 0;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };


void Input();
int Solve();

void DFS(int y, int x, int cnt, int val);
void ClearVisit();

int main() {

	Input();

	cout << Solve() << endl;

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

int Solve()
{

	int ret = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			DFS(i, j, 1, arr[i][j]);
			visit[i][j] = 0;
			ret = max(ret, _max);
		}
	}

	return ret;
}

void DFS(int y, int x, int cnt, int val)
{
	// Check 4-ways
	// 
	visit[y][x] = 1;

	if (cnt == 2) {
		for (int i = 0; i < 4; i++) {
			int ny1 = y + dy[i];
			int nx1 = x + dx[i];

			int ny2 = y + dy[(i+1)%4];
			int nx2 = x + dx[(i+1)%4];

			if (ny1 >= 0 && ny1 < n && nx1 >= 0 && nx1 < m &&
				ny2 >= 0 && ny2 < n && nx2 >= 0 && nx2 < m) {
				if (visit[ny1][nx1] == 0 && visit[ny2][nx2]==0) {
					_max = max(_max, val + arr[ny1][nx1] + arr[ny2][nx2]);
					
				}
			}
		}
	}

	if (cnt == 4) {
		_max = max(_max, val);
		
		return;
	}

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
			if (visit[ny][nx] == 0) {
				DFS(ny, nx, cnt + 1, val + arr[ny][nx]);
				visit[ny][nx] = 0;
			}
		}
			
	}

}

void ClearVisit()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			visit[i][j] = 0;
}


