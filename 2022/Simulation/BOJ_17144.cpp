#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
int arr[50][50];

vector<pair<int, int>> pos_dust;	// y, x
vector<int> yPos_AirCleaner;		// y


int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void Input();

void Diffusion();
void AirCleaner();
int GetAmountDust();

void Print() {
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

int main() {

	Input();

	for (int i = 0; i < k; i++) {

		Diffusion();
		AirCleaner();
	}

	cout << GetAmountDust() << endl;

	return 0;
}

void Input()
{
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == -1)
				yPos_AirCleaner.push_back(i);
		}
	}
}

void Diffusion()
{
	pos_dust.clear();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == -1)
				continue;
			pos_dust.push_back(make_pair(i, j));
		}
	}

	int temp[50][50] = { 0, };

	for (auto dust : pos_dust) {

		int y = dust.first;
		int x = dust.second;

		int diffusion_cnt = 0;
		for (int i = 0; i < 4; i++) {

			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
				if (arr[ny][nx] != -1) {
					diffusion_cnt++;
				}
			}
		}
		int dust_add = arr[y][x] / 5;
		temp[y][x] -= diffusion_cnt * dust_add;
		for (int i = 0; i < 4; i++) {

			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
				if (arr[ny][nx] != -1) {
					temp[ny][nx] += dust_add;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] += temp[i][j];
		}
	}
}

void AirCleaner()
{
	// Upwward
	for (int i = yPos_AirCleaner[0]; i >= 1; i--) {
		if (arr[i][0] == -1)
			continue;
		arr[i][0] = arr[i - 1][0];
	}
	for (int j = 0; j <= m - 2; j++) {
		arr[0][j] = arr[0][j + 1];
	}
	for (int i = 0; i < yPos_AirCleaner[0]; i++) {
		arr[i][m - 1] = arr[i + 1][m - 1];
	}
	for (int j = m - 1; j >= 1; j--) {
		if (j == 1)
			arr[yPos_AirCleaner[0]][j] = 0;
		else
			arr[yPos_AirCleaner[0]][j] = arr[yPos_AirCleaner[0]][j - 1];
	}

	// Downward
	for (int i = yPos_AirCleaner[1]; i <= n - 2; i++) {
		if (arr[i][0] == -1)
			continue;
		arr[i][0] = arr[i + 1][0];
	}
	for (int j = 0; j <= m - 2; j++) {
		arr[n - 1][j] = arr[n - 1][j + 1];
	}
	for (int i = n - 1; i >= yPos_AirCleaner[1] + 1; i--) {
		arr[i][m - 1] = arr[i - 1][m - 1];
	}
	for (int j = m - 1; j >= 1; j--) {
		if (j == 1)
			arr[yPos_AirCleaner[1]][j] = 0;
		else
			arr[yPos_AirCleaner[1]][j] = arr[yPos_AirCleaner[1]][j - 1];
	}
	pos_dust.clear();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == -1)
				continue;
			pos_dust.push_back(make_pair(i, j));
		}
	}
}

int GetAmountDust()
{
	int dust = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == -1)
				continue;
			dust += arr[i][j];
		}
	}

	return dust;
}
