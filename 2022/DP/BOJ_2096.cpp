#include <iostream>
using namespace std;

int n;

int arr[3];
int dp_min[2][3] = { 0, };
int dp_max[2][3] = { 0, };

int _min = 99999999;
int _max = -1;

int main() {

	cin >> n;


	for (int i = 0; i < 3; i++) {
		int temp;
		cin >> temp;
		dp_min[0][i] = temp;
		dp_max[0][i] = temp;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[j];
			dp_min[i % 2][j] = arr[j];
			dp_max[i % 2][j] = arr[j];
			if (j == 0) {
				dp_min[i % 2][j] += min(dp_min[(i + 1) % 2][j], dp_min[(i + 1) % 2][j + 1]);
				dp_max[i % 2][j] += max(dp_max[(i + 1) % 2][j], dp_max[(i + 1) % 2][j + 1]);
			}
			else if (j == 1) {
				dp_min[i % 2][j] += min(min(dp_min[(i + 1) % 2][j - 1], dp_min[(i + 1) % 2][j]), dp_min[(i + 1) % 2][j + 1]);
				dp_max[i % 2][j] += max(max(dp_max[(i + 1) % 2][j - 1], dp_max[(i + 1) % 2][j]), dp_max[(i + 1) % 2][j + 1]);
			}
			else {
				dp_min[i % 2][j] += min(dp_min[(i + 1) % 2][j], dp_min[(i + 1) % 2][j - 1]);
				dp_max[i % 2][j] += max(dp_max[(i + 1) % 2][j], dp_max[(i + 1) % 2][j - 1]);
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		if (dp_min[(n + 1) % 2][i] < _min)
			_min = dp_min[(n + 1) % 2][i];
		if (dp_max[(n + 1) % 2][i] > _max)
			_max = dp_max[(n + 1) % 2][i];
	}




	cout << _max << " " << _min << endl;


	return 0;
}