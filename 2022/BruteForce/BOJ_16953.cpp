#include <iostream>
#include <algorithm>
using namespace std;

#define MAX		1000000001
long long int a, b;

long long int dfs(long long int num, long long int cnt) {
	if (num > b)
		return MAX;

	if (num == b)
		return cnt;

	return min(dfs(num * 2, cnt + 1), dfs(num * 10 + 1, cnt + 1));

}

int main() {

	cin >> a >> b;

	long long int val = dfs(a, 1);

	cout << (val == MAX ? -1 : val) << endl;

	return 0;
}