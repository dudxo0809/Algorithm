#include <iostream>
#include <vector>
using namespace std;

bool flag = false;
int arr[9][9];
std::vector<pair<int, int>> v; // (y,x)
std::vector<bool> visit;

void Input();
void dfs(int cnt);
bool Check(int val, int idx);

int main() {

	Input();
	dfs(0);


	return 0;
}

void dfs(int cnt) {
	if (flag == true)
		return;
	if (v.size() == cnt) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
		flag = true;
	}
	else {
		for (int val = 1; val <= 9; val++) {
			if (!visit[cnt] && Check(val, cnt)) {
				arr[v[cnt].first][v[cnt].second] = val;
				visit[cnt] = true;
				dfs(cnt + 1);
				visit[cnt] = false;
				arr[v[cnt].first][v[cnt].second] = 0;
			}
		}
	}
}
/*
	idx : ���� Ž���� v�� ���� idx
	val : ���� idx���� �õ��� �� ��

*/
bool Check(int val, int idx) {
	int x = v[idx].second;
	int y = v[idx].first;

	//���� ��ǥ���� ����,����, ���簢�� Ž��
	for (int i = 0; i < 9; i++) {
		if (val == arr[y][i] || val == arr[i][x])	// ���μ���
			return false;
	}
	for (int i = (y - y % 3); i < (y - y % 3) + 3; i++) {
		for (int j = (x - x % 3); j < (x - x % 3) + 3; j++) {
			if (val == arr[i][j])
				return false;
		}
	}
	// 5,4 => 3,3 ~ 5,5
	// 7,2 => 6,0 ~ 8,2

	// s : 3�� ���� �������� ��
	// e : ..

	return true;
}

void Input() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) {
				v.push_back(make_pair(i, j));
				visit.push_back(false);
			}
		}
	}

}