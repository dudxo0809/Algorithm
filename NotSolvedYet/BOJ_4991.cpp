
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int w, h;
char arr[20][20];
int visit[20][20];

int n_dirty;
int dist_move;

int dist_dirty[10][10];
int dist_cleanerToDirty[10];

pair<int, int> pos_cleaner;
vector<pair<int, int>> pos_dirty;


int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void Simulation();
void Input();
bool MakeDistDirty();
bool MakeDistDirtyToCleaner();
void PrintResult();

void VisitClear();

bool BFS(pair<int, int> pos_start, pair<int, int> pos_end, int& dist);

void PrintDist() {
	for (int i = 0; i < n_dirty; i++) {
		for (int j = 0; j < n_dirty; j++) {

			cout << dist_dirty[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {

	Simulation();

	return 0;
}

void Simulation()
{
	while (true) {

		// One Test Case
		Input();

		// Matrix dist_dirty
		if (!MakeDistDirty())
			break;

		// Make dist_cleanerToDirty
		if (!MakeDistDirtyToCleaner())
			break;

		// Exit Program Command
		if (w == 0 && h == 0)
			break;

		// Debuging
		//PrintDist();

		// Use TSP Algorithm!
		// 
		//

	}
}

void Input()
{
	n_dirty = 0;
	dist_move = 0;
	pos_dirty.clear();

	cin >> w >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {

			visit[i][j] = -1;

			cin >> arr[i][j];
			if (arr[i][j] == '*') {
				n_dirty++;
				pos_dirty.push_back(make_pair(i, j));
			}
			else if (arr[i][j] == 'o') {
				pos_cleaner = make_pair(i, j);
				arr[i][j] = '.';
			}
		}
	}
}

bool MakeDistDirty()
{
	for (int i = 0; i < n_dirty; i++) {
		for (int j = 0; j < n_dirty; j++) {
			if (i == j)
				dist_dirty[i][j] = 0;
			else {
				// Clear Visit array
				VisitClear();

				// Do BFS!
				int dist = -1;
				if (!BFS(pos_dirty[i], pos_dirty[j], dist))
					return false;
				dist_dirty[j][i] = dist;
				dist_dirty[i][j] = dist;
			}
		}
	}
	return true;
}

bool MakeDistDirtyToCleaner()
{
	for (int i = 0; i < n_dirty; i++) {
		// Clear Visit array
		VisitClear();

		// Do BFS
		int dist = -1;
		if (!BFS(pos_cleaner, pos_dirty[i], dist))
			return false;
		dist_cleanerToDirty[i] = dist;
	}
	return true;
}

void PrintResult()
{
	if (n_dirty > 0)
		cout << -1 << endl;
	else
		cout << dist_move << endl;
}

void VisitClear()
{
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			visit[i][j] = -1;
		}
	}
}

bool BFS(pair<int, int> pos_start, pair<int, int> pos_end, int& dist)
{
	queue<pair<int, int>> q;

	visit[pos_start.first][pos_start.second] = 0;

	q.push(pos_start);
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny < h && nx >= 0 && nx < w) {
				if (visit[ny][nx] == -1 && arr[ny][nx] != 'x') {
					// Can Move

					visit[ny][nx] = visit[y][x] + 1;

					if (ny == pos_end.first && nx == pos_end.second) {

						// Found!
						dist = visit[ny][nx];

						return true;
					}
					else {
						q.push(make_pair(ny, nx));
					}


				}
			}
		}
	}

	// Can't find dirty spot
	return false;
}
