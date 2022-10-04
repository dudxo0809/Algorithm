#include <iostream>
#include <vector>
using namespace std;

int n, m, x, y, k;
int arr[20][20];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

vector<int> answer;

int dice[7] = { 0, };	// 0, 1 2 3 4 5 6 

int Func(int dir);

int main() {

	cin >> n >> m >> y >> x >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	for (int i = 0; i < k; i++) {
		int num, dir;
		cin >> dir;

		num = Func(dir);
		if (num != -1)
			answer.push_back(num);
	}

	for (auto i : answer)
		cout << i << endl;

	return 0;
}

int Func(int dir)
{
	int nx = x + dx[dir - 1];
	int ny = y + dy[dir - 1];

	if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
		switch (dir) {
		case 1:	// right

			if (arr[ny][nx] == 0)
				arr[ny][nx] = dice[3];
			else {
				dice[3] = arr[ny][nx];
				arr[ny][nx] = 0;
			}
			dice[0] = dice[4];
			dice[4] = dice[1];
			dice[1] = dice[3];
			dice[3] = dice[6];
			dice[6] = dice[0];

			break;
		case 2:	// left

			if (arr[ny][nx] == 0)
				arr[ny][nx] = dice[4];
			else {
				dice[4] = arr[ny][nx];
				arr[ny][nx] = 0;
			}
			dice[0] = dice[1];
			dice[1] = dice[4];
			dice[4] = dice[6];
			dice[6] = dice[3];
			dice[3] = dice[0];

			break;
		case 3:	// up

			if (arr[ny][nx] == 0)
				arr[ny][nx] = dice[2];
			else {
				dice[2] = arr[ny][nx];
				arr[ny][nx] = 0;
			}
			dice[0] = dice[1];
			dice[1] = dice[2];
			dice[2] = dice[6];
			dice[6] = dice[5];
			dice[5] = dice[0];

			break;
		case 4:	// down

			if (arr[ny][nx] == 0)
				arr[ny][nx] = dice[5];
			else {
				dice[5] = arr[ny][nx];
				arr[ny][nx] = 0;
			}
			dice[0] = dice[1];
			dice[1] = dice[5];
			dice[5] = dice[6];
			dice[6] = dice[2];
			dice[2] = dice[0];

			break;
		default:
			break;
		}

		x = nx;
		y = ny;

		return dice[6];
	}
	else {
		return -1;
	}
}
