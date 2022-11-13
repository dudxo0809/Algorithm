#include <iostream>
#include <queue>
using namespace std;


int n, m;
int arr[1000][1000];
int visit[1000][1000];
pair<int, int> room_info[1000][1000];	// <idx, size>;


int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };


void Input();
void FindEachRoomSize();
void PrintAnswer();

int GetRoomSize(int i, int j);
void SetRoomInfo(int i, int j, int idx, int room_size);

int GetMovableRoomNum(int i, int j);

bool IsInBoundary(int ny, int nx);

int main() {

	Input();

	FindEachRoomSize();

	PrintAnswer();

	return 0;
}

void Input()
{
	vector<string> v;
	string s;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = (v[i][j] == '1' ? 1 : 0);
			room_info[i][j].first = -1;
		}
	}
}

void FindEachRoomSize()
{
	int idx = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0 && visit[i][j] == 0) {

				// Get Room Size
				int room_size = GetRoomSize(i, j);

				//Initialize Room <idx, size> in room_info
				SetRoomInfo(i, j, idx, room_size);
				idx++;
			}

		}
	}
}

void PrintAnswer()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0)
				cout << 0;
			else {
				cout << (GetMovableRoomNum(i, j) % 10);
			}
		}
		cout << endl;
	}
}

int GetRoomSize(int i, int j)
{
	// BFS start
	int room_size = 1;

	visit[i][j] = true;
	queue<pair<int, int>> q;	// y,x
	q.push(make_pair(i, j));
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (IsInBoundary(ny, nx)) {	// check boundary & visit
				if (visit[ny][nx] == 0 && arr[ny][nx] == 0) {
					q.push(make_pair(ny, nx));
					visit[ny][nx] = 1;
					room_size++;
				}
			}
		}
	}
	return room_size;
}

void SetRoomInfo(int i, int j, int idx, int room_size)
{
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	visit[i][j] = 2;
	room_info[i][j] = make_pair(idx, room_size);
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (IsInBoundary(ny, nx)) {	// check boundary & visit
				if (visit[ny][nx] == 1 && arr[ny][nx] == 0) {
					q.push(make_pair(ny, nx));
					visit[ny][nx] = 2;
					room_info[ny][nx] = make_pair(idx, room_size);
				}
			}
		}
	}
}

int GetMovableRoomNum(int i, int j)
{
	int ret = 1;	// cell (y = i, x = j)

	vector<int> visit_idx;
	for (int k = 0; k < 4; k++) {
		int ny = i + dy[k];
		int nx = j + dx[k];
		if (IsInBoundary(ny, nx)) {

			bool check = false;
			for (auto v : visit_idx) {
				if (room_info[ny][nx].first == v)
					check = true;
			}
			if (check == false) {
				visit_idx.push_back(room_info[ny][nx].first);
				ret += room_info[ny][nx].second;
			}
		}
	}

	return ret;
}

bool IsInBoundary(int ny, int nx)
{
	if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
		return true;
	}
	return false;
}
