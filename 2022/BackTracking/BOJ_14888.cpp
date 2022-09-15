#include <iostream>
#include <vector>
using namespace std;

int n;

int _max = -1000000000;
int _min = 1000000000;

vector<int> op(4);	// + - * /
vector<int> arr;

vector<char> result;
char ch_arr[4] = { '+', '-', '*', '/' };

void Input();
void dfs(int cnt);

int main() {

	Input();
	dfs(0);

	cout << _max << endl;
	cout << _min << endl;

	return 0;
}

void Input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}
}

void dfs(int cnt) {
	if (cnt == n - 1) {

		int sum = arr[0];
		for (int i = 0; i < result.size(); i++) {
			if (result[i] == '+') {
				sum += arr[i + 1];
			}
			else if (result[i] == '-') {
				sum -= arr[i + 1];
			}
			else if (result[i] == '*') {
				sum *= arr[i + 1];
			}
			else {
				sum /= arr[i + 1];
			}
		}

		if (sum > _max)
			_max = sum;
		if (sum < _min)
			_min = sum;
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (op[i] >= 1) {
				op[i]--;
				result.push_back(ch_arr[i]);
				dfs(cnt + 1);
				op[i]++;
				result.pop_back();
			}
		}
	}
}
