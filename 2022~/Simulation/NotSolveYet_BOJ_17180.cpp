//
// 
// Not Solve Yet
// 
// https://www.acmicpc.net/problem/17780
// 
// BOJ17780
// 
// 
//



#include <iostream>
#include <vector>
using namespace std;

struct Pawn {
	int y, x;
	int dir;
	int idx;
};

int n, k;

int map[12][12];
vector<Pawn> pawn[12][12];
vector<Pawn> pawn_seq;

int dx[5] = { 0,1,-1,0,0 };
int dy[5] = { 0,0,0,-1,1 };

void Input();
void Simulation();

bool CheckGameEnd();

void MovePawn(Pawn& p);

int main() {

	Input();

	Simulation();


	return 0;
}

void Input()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	}

	for (int i = 0; i < k; i++) {

		int y, x, dir;

		cin >> y >> x >> dir;

		y--; x--;
		pawn_seq.push_back(Pawn({ y,x,dir,i }));

		pawn[y][x].push_back(pawn_seq.back());

	}
}

void Simulation()
{
	int sim_cnt = 0;
	bool bGameEnd = false;


	while (sim_cnt <= 1000 && !bGameEnd) {

		sim_cnt++;

		for (auto& p : pawn_seq) {
			if (CheckGameEnd()) {

				bGameEnd = true;
				break;
			}
			MovePawn(p);
		}
	}

	if (sim_cnt > 1000 && !bGameEnd)
		cout << -1 << endl;
	else
		cout << sim_cnt << endl;
}

bool CheckGameEnd()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (pawn[i][j].size() >= 4)
				return true;
		}
	}
	return false;
}

void MovePawn(Pawn& p)
{
	if (pawn[p.y][p.x][0].idx != p.idx)
		return;

	int ny = p.y + dy[p.dir];
	int nx = p.x + dx[p.dir];

	if (!(ny >= 0 && ny < n && nx >= 0 && nx < n)) {
		// Out of Range : act like Blue
		if (p.dir == 1) p.dir = 2;
		else if (p.dir == 2) p.dir = 1;
		else if (p.dir == 3) p.dir = 4;
		else if (p.dir == 4) p.dir = 3;


		ny = p.y + dy[p.dir];
		nx = p.x + dx[p.dir];
		if (ny >= 0 && ny < n && nx >= 0 && nx < n)
			if (map[ny][nx] != 2)
				MovePawn(p);
	}

	else if (map[ny][nx] == 2) {
		// Blue
		if (p.dir == 1) p.dir = 2;
		else if (p.dir == 2) p.dir = 1;
		else if (p.dir == 3) p.dir = 4;
		else if (p.dir == 4) p.dir = 3;


		ny = p.y + dy[p.dir];
		nx = p.x + dx[p.dir];
		if (ny >= 0 && ny < n && nx >= 0 && nx < n)
			if (map[ny][nx] != 2)
				MovePawn(p);

	}

	else if (map[ny][nx] == 1) {
		// Red
		int n_pawn = pawn[p.y][p.x].size();

		for (int i = 0; i < n_pawn; i++) {
			pawn[ny][nx].push_back(pawn[p.y][p.x].back());
			pawn[p.y][p.x].pop_back();
		}
		for (auto& _p : pawn[ny][nx]) {
			_p.y = ny; _p.x = nx;
			pawn_seq[_p.idx] = _p;
		}
	}

	else {
		// White
		for (auto& _p : pawn[p.y][p.x]) {
			_p.y = ny; _p.x = nx;
			pawn_seq[_p.idx] = _p;
			pawn[ny][nx].push_back(_p);
		}
		pawn[p.y][p.x].clear();
	}
}
