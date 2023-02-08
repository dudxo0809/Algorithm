#include <iostream>
#include <queue>
using namespace std;

int n;
priority_queue<int, vector<int>, less<int>> max_pq;
priority_queue<int, vector<int>, greater<int>> min_pq;

/*

max_pq.top()

max		min
5 2 1 -99		5 7 10


*/



int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (unsigned int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (i % 2 == 0) {
			max_pq.push(num);
		}
		else {
			min_pq.push(num);
		}
		if (!max_pq.empty() && !min_pq.empty()) {
			if (max_pq.top() > min_pq.top()) {
				int go_min = max_pq.top();
				int go_max = min_pq.top();
				
				max_pq.pop();
				min_pq.pop();

				max_pq.push(go_max);
				min_pq.push(go_min);
			}
		}
		cout << max_pq.top() << "\n";
	}


	return 0;
}