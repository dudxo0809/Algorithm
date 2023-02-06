#include <iostream>
#include <queue>
#include<stack>
using namespace std;

int n, k;
int dist[100001];
int before[100001];

int min_dist;

void InputAndInit();
bool IsInBoundary(int n);
void PrintSequence(int k);
void BFS();


int main() {

	InputAndInit();

	BFS();


	return 0;
}

void InputAndInit() {
	cin >> n >> k;

	for (int i = 0; i <= 100000; i++)
		dist[i] = -1;
}

bool IsInBoundary(int n) {
	if (n >= 0 && n <= 100000) {
		if (dist[n] == -1)
			return true;
	}
	return false;
}

void PrintSequence(int k) {

	stack<int> seq;

	int cur = k;

	while (k != n) {
		seq.push(k);
		k = before[k];
	}
	seq.push(k);

	while (!seq.empty()) {
		cout << seq.top() << " ";
		seq.pop();
	}
}

void BFS() {
	queue<int> q;
	q.push(n);
	dist[n] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == k) {
			cout << dist[cur] << endl;
			PrintSequence(cur);
			return;
		}

		for (int i = 0; i < 3; i++) {
			int n_cur;
			if (i == 0) {
				n_cur = cur - 1;
			}
			else if (i == 1) {
				n_cur = cur + 1;
			}
			else {
				n_cur = cur * 2;
			}
			if (IsInBoundary(n_cur)) {
				q.push(n_cur);
				dist[n_cur] = dist[cur] + 1;
				before[n_cur] = cur;
			}
		}
	}
}
