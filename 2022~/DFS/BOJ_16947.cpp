#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<int> subway[3001];
bool visited[3001];
int N;


void Input();
bool dfs(int start, int from, int cnt);
int bfs(int start);


int main()
{
	Input();


	for (int i = 1; i <= N; i++)
		if (dfs(i, i, 1))
			break;

	for (int i = 1; i <= N; i++)
		if (visited[i])
			cout << "0 ";
		else
			cout << bfs(i) << " ";

	return 0;
}

void Input()
{
	cin >> N;
	for (int n = 0; n < N; n++)
	{
		int a, b;
		cin >> a >> b;

		subway[a].push_back(b);
		subway[b].push_back(a);
	}
}

bool dfs(int start, int from, int cnt)
{

	visited[from] = true;

	for (int i = 0; i < subway[from].size(); i++)
	{
		int to = subway[from][i];

		if (3 <= cnt && to == start)
			return true;
		else if (!visited[to])
			if (dfs(start, to, cnt + 1))
				return true;
	}
	visited[from] = false;

	return false;
}

int bfs(int start)
{
	queue<int> q;

	int visitedBFS[3001] = { 0, };

	visitedBFS[start] = 1;
	q.push(start);


	while (!q.empty()) {
		int from = q.front();

		q.pop();

		for (int i = 0; i < subway[from].size(); i++) {
			int to = subway[from][i];

			if (visitedBFS[to] != 0)
				continue;

			else if (visited[to])
				return visitedBFS[from];
			else {
				visitedBFS[to] = visitedBFS[from] + 1;
				q.push(to);
			}
		}
	}

	return -1;
}