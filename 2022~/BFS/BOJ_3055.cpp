//
// water < hog : cna Move
// 
#include <iostream>
#include <queue>
using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int n, m;
char map[50][50];
int water_visit[50][50];
int hog_visit[50][50];

pair<int, int> dest;

// (y,x)
queue<pair<int, int>> water_pos, hog_pos;

void Init();
void Input();
void Water();
void Hog();

bool MoveCheck_Water(int ny, int nx);
bool MoveCheck_Hog(int ny, int nx, int cutrent_visit);

void PrintMap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << water_visit[i][j] << " ";
		cout << endl;
	}
}

int main() {

	Init();

	Input();

	Water();

	//PrintMap();
	Hog();

	if (hog_visit[dest.first][dest.second] == -1)
		cout << "KAKTUS" << endl;
	else
		cout << hog_visit[dest.first][dest.second] << endl;


	return 0;
}

void Hog() {
	while (!hog_pos.empty()) {
		int x = hog_pos.front().second;
		int y = hog_pos.front().first;
		hog_pos.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (MoveCheck_Hog(ny, nx, hog_visit[y][x])) {
				hog_pos.push(make_pair(ny, nx));
				hog_visit[ny][nx] = hog_visit[y][x] + 1;
			}
		}
	}
}

void Input()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == '*') {
				water_pos.push(make_pair(i, j));
				water_visit[i][j] = 0;
			}
			else if (map[i][j] == 'S') {
				hog_pos.push(make_pair(i, j));
				hog_visit[i][j] = 0;
			}
			else if (map[i][j] == 'D') {
				dest.first = i;
				dest.second = j;
			}
		}
}

void Water()
{
	while (!water_pos.empty()) {
		int y = water_pos.front().first;
		int x = water_pos.front().second;
		water_pos.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (MoveCheck_Water(ny, nx)) {
				water_pos.push(make_pair(ny, nx));
				water_visit[ny][nx] = water_visit[y][x] + 1;
			}
		}
	}
}

bool MoveCheck_Water(int ny, int nx)
{
	// check wall & dest
	if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
		if ((map[ny][nx] == '.' || map[ny][nx] == 'S') && water_visit[ny][nx] == -1) {
			return true;
		}
	}
	return false;
}

bool MoveCheck_Hog(int ny, int nx, int current_visit) {

	if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
		if ((map[ny][nx] == '.' || map[ny][nx] == 'D') && hog_visit[ny][nx] == -1) {
			if (current_visit + 1 < water_visit[ny][nx] || map[ny][nx] == 'D' || water_visit[ny][nx] == -1)
				return true;
		}
	}

	return false;
}

void Init() {
	for (int i = 0; i < 50; i++)
		for (int j = 0; j < 50; j++) {
			water_visit[i][j] = -1;
			hog_visit[i][j] = -1;
		}
}