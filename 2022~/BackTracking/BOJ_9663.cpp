#include <iostream>
#include <vector>
using namespace std;

int n;
int result;
vector<int> v;

void dfs(int num);
bool Check(int column);

int main() {

	cin >> n;
	dfs(0);

	cout << result << endl;

	return 0;
}
/*

v.size() == 4;

xoxx => v : 1 3 0 2
xxxo
oxxx
xxox

xxox  v[0] = 2
xoxx  v[1] = 1

*/
void dfs(int num) {

	if (num == n)
		result++;
	else {
		for (int i = 0; i < n; i++) {
			if (Check(i)) {
				v.push_back(i);
				dfs(num + 1);
				v.pop_back();
			}
		}
	}
}

bool Check(int column) {
	// 중복 : 같은 행 (v.size) / 열 : value
	// 대각선 : 
	for (int i = 0; i < v.size(); i++) {
		if (column == v[i]) // same column
			return false;
		else if (abs((int)(v.size() - i)) == abs(v[i] - column)) { // 대각선
			return false;
		}
	}

	return true;
}