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

// ġ�� ����ã��
// �ܺ�0, ġ�� 1�� �ʱ�ȭ
// �̰� bfs

// ġ�� ��� ���� �ݺ��ϸ鼭 0�� 2�̻� �����°� 2�� ����
// �̶� �ѹ� �ݺ��� ������ bfs����
// �� �ݺ����� cnt++;

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

// visit == false && arr[i][j] == 0 �̸� ���� ����!
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

//�ܺΰ���� ���ΰ��� �Ǻ�
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

// ����� �ι����� ġ��� arr[i][j] = 2 �� �ʱ�ȭ!
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

	// ����� �ι����� ġ�� ���� & ��� visit false�� �ʱ�ȭ
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 2)
				arr[i][j] = 0;
			visit[i][j] = false;
		}
	}
}

// ���� �ʿ� ġ� �����ִ��� Ȯ��
bool Check() {
	return !cheese.empty();
}