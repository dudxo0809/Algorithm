/*

	BOJ 2805
	https://www.acmicpc.net/problem/2805

*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


long long int n, m;
vector<int> tree;

void Input();
long long int Solve();

int main() {

	Input();
	cout << Solve() << endl;

	return 0;
}

void Input()
{
	long long int temp; 

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		tree.push_back(temp);
	}

	sort(tree.begin(), tree.end());
}

long long int Solve()
{
	
	long long int min = 0;
	long long int max = tree[n - 1];
	long long int mid = 0;
	
	while (min <= max) {
		
		mid = (min + max) / 2;
		long long int sum = 0;

		for (auto i : tree) {
			if (i > mid)
				sum += (i - mid);
		}

		if (sum >= m) {
			min = mid + 1;
			
		}
		else {
			max = mid - 1;
		}

	}

	return max;
}
