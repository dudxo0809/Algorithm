#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



struct Shark {
	int y;
	int x;

	int speed;
	int dir;
	int size;

};

bool Pred(Shark s1, Shark s2) {
	if (s1.x == s2.x)
		return s1.y < s2.y;
	return s1.x < s2.x;
}


int n, m, n_shark;
int total_shark_size = 0;

vector<Shark> v_shark[100][100];

int xPos_Fisherman;

int dx[5] = { 0,0,0,1,-1 };
int dy[5] = { 0,-1,1,0,0 };

void Input();
void Initialize();
void Simulate();

void MoveFisherman();
void Fishing();
void MoveShark();


int main() {

	Input();
	Initialize();

	Simulate();

	return 0;
}

void Input()
{
	cin >> n >> m >> n_shark;

	for (int i = 0; i < n_shark; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;

		r--; c--;
		if (d == 1 || d == 2)
			s %= ((n - 1) * 2);
		if (d == 3 || d == 4)
			s %= ((m - 1) * 2);

		v_shark[r][c].push_back(Shark({ r, c, s, d, z }));
	}
}

void Initialize()
{
	xPos_Fisherman = -1;
}

void Simulate()
{
	for (int i = 0; i < m; i++) {

		MoveFisherman();
		Fishing();
		MoveShark();
		//cout << total_shark_size << endl;
	}

	cout << total_shark_size << endl;
}

void MoveFisherman()
{
	xPos_Fisherman++;
}

void Fishing()
{
	for (int i = 0; i < n; i++) {
		if (!v_shark[i][xPos_Fisherman].empty()) {

			total_shark_size += v_shark[i][xPos_Fisherman][0].size;
			v_shark[i][xPos_Fisherman].pop_back();

			break;
		}
	}
}

void MoveShark()
{
	vector<Shark> v_shark_move[100][100];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			if (v_shark[i][j].empty())
				continue;

			Shark& cur_shark = v_shark[i][j][0];
			v_shark[i][j].pop_back();

			for (int k = 0; k < cur_shark.speed; k++) {
				int ny = cur_shark.y + dy[cur_shark.dir];
				int nx = cur_shark.x + dx[cur_shark.dir];

				if (!(ny >= 0 && ny < n && nx >= 0 && nx < m)) {
					switch (cur_shark.dir)
					{
					case 1: cur_shark.dir = 2;
						break;
					case 2: cur_shark.dir = 1;
						break;
					case 3: cur_shark.dir = 4;
						break;
					case 4: cur_shark.dir = 3;
						break;
					default:
						break;
					}
				}
				cur_shark.y += dy[cur_shark.dir];
				cur_shark.x += dx[cur_shark.dir];
			}

			if (!v_shark_move[cur_shark.y][cur_shark.x].empty()) {
				if (v_shark_move[cur_shark.y][cur_shark.x][0].size < cur_shark.size) {

					v_shark_move[cur_shark.y][cur_shark.x].pop_back();
					v_shark_move[cur_shark.y][cur_shark.x].push_back(cur_shark);
				}
			}
			else
				v_shark_move[cur_shark.y][cur_shark.x].push_back(cur_shark);
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			v_shark[i][j] = v_shark_move[i][j];

}
