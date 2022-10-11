#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

struct Cell {
	// left, up, right, down
	int cell[4];
};

int n, m;

int RoomNum = 0;
int LargestRoomScale = 0;
int LargestRoomScaleBreakWall = 0;

vector<int> RoomScale;
vector<vector<int>> ContactedRoom;

Cell arr[50][50];
int visit[50][50];

void SetCell(int y, int x, int val);
void Input();
void GetRoomNum();
void GetLargestRoomScale();
void GetLargestRoomScaleBreakWall();

bool CheckMovable(Cell s, Cell e, int dir);
bool CheckRoomContact(int Room1, int Room2);

int main() {

	Input();

	GetRoomNum();

	GetLargestRoomScale();

	GetLargestRoomScaleBreakWall();


	cout << RoomNum << endl;
	cout << LargestRoomScale << endl;
	cout << LargestRoomScaleBreakWall << endl;

	return 0;
}

void SetCell(int y, int x, int val) {
	int divider = 8;
	for (int i = 3; i >= 0; i--) {
		arr[y][x].cell[i] = val / divider;
		val %= divider;
		divider /= 2;
	}
}

void Input() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int temp;
			cin >> temp;
			SetCell(i, j, temp);
		}
	}
}

void GetRoomNum() {

	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visit[i][j] == 0) {

				RoomNum++;
				RoomScale.push_back(1);

				q.push(make_pair(i, j));
				visit[i][j] = RoomNum;

				while (!q.empty()) {
					int y = q.front().first;
					int x = q.front().second;

					q.pop();

					for (int k = 0; k < 4; k++) {
						int ny = y + dy[k];
						int nx = x + dx[k];

						if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
							if (visit[ny][nx] == 0 && CheckMovable(arr[y][x], arr[ny][nx], k)) {

								visit[ny][nx] = RoomNum;
								q.push(make_pair(ny, nx));
								RoomScale[RoomNum - 1]++;
							}

						}
					}
				}
			}
		}
	}


}

bool CheckMovable(Cell s, Cell e, int dir) {
	// dir 의 index가 서로 0이어야함
	return (s.cell[dir] == 0 && e.cell[(dir + 2) % 4] == 0);
}

void GetLargestRoomScale() {
	for (auto i : RoomScale) {
		if (i > LargestRoomScale)
			LargestRoomScale = i;
	}
}

void GetLargestRoomScaleBreakWall() {

	int Max_Scale = 0;

	for (int i = 1; i <= RoomNum; i++) {
		for (int j = i + 1; j <= RoomNum; j++) {
			if (CheckRoomContact(i, j)) {
				if ((RoomScale[i - 1] + RoomScale[j - 1]) > Max_Scale)
					Max_Scale = RoomScale[i - 1] + RoomScale[j - 1];
			}
		}
	}

	LargestRoomScaleBreakWall = Max_Scale;
}

bool CheckRoomContact(int Room1, int Room2) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visit[i][j] == Room1) {
				for (int k = 0; k < 4; k++) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
						if (visit[ny][nx] == Room2)
							return true;
					}
				}
			}
		}
	}

	return false;
}
