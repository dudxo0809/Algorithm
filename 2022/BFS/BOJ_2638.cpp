#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;

int cnt;

int arr[100][100] = { 0, };
bool visit[100][100] = { false, };

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

queue<pair<int, int>> cheese;	// (i,j)
queue<pair<int, int>> q;


void Input();
void bfs();
void Cheese();
bool Check();

// 치즈 내부찾고
// 외부0, 치즈 1로 초기화
// 이게 bfs

// 치즈 모든 지점 반복하면서 0과 2이상 만나는곳 2로 변경
// 이때 한번 반복할 때마다 bfs진행
// 매 반복마다 cnt++;

int main() {

	Input();

	while (1) {

		if (Check()) {
			cnt++;
			q.push(make_pair(0, 0));
			bfs(); // found
			Cheese();
		}
		else {
			break;
		}
	}

	cout << cnt << endl;

	return 0;
}

// visit == false && arr[i][j] == 0 이면 내부 공기!
void Input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				cheese.push(make_pair(i, j));
		}
	}
}

//외부공기와 내부공기 판별
void bfs() {	// Initialize visit

	while (!q.empty()) {

		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < m && ny < n
				&& arr[ny][nx] == 0) {

				if (!visit[ny][nx]) {
					visit[ny][nx] = true;
					q.push(make_pair(ny, nx));

				}
			}
		}
	}
}

// 공기와 두번닿은 치즈는 arr[i][j] = 2 로 초기화!
void Cheese()
{
	int len = cheese.size();
	for (int i = 0; i < len; i++) {
		int n_air = 0;
		int x = cheese.front().second;
		int y = cheese.front().first;
		cheese.pop();
		for (int i = 0; i < 4; i++) {

			int nx = x + dx[i];
			int ny = y + dy[i];
			if (arr[ny][nx] == 0 && visit[ny][nx])
				n_air++;
		}
		if (n_air >= 2) {
			arr[y][x] = 2;
		}
		else
			cheese.push(make_pair(y, x));
	}

	// 공기와 두번닿은 치즈 제거 & 모든 visit false로 초기화
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 2)
				arr[i][j] = 0;
			visit[i][j] = false;
		}
	}
}

// 현재 맵에 치즈가 남아있는지 확인
bool Check() {
	return !cheese.empty();
}