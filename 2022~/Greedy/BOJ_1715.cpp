#include <iostream>
#include <queue>
using namespace std;


int n;
priority_queue<int, vector<int>, greater<int>> pq;



int main() {


	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		pq.push(temp);
	}

	int sum = 0;
	while (pq.size() > 1) {
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();

		sum += (a + b);
		pq.push(a + b);
	}

	cout << sum << endl;

	return 0;
}