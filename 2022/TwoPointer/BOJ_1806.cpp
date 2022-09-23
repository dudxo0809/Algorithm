#include <iostream>
using namespace std;

#define MAX		9999999

int n, m;
int arr[100000];

int s, e;

int min_len = MAX;

int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	s = 0; e = 0;

	int sum = arr[0];
	while (s < n && e < n) {
		if (sum >= m) {
			int len = e - s + 1;
			if (len < min_len)
				min_len = len;

			sum -= arr[s];
			s++;
		}
		else if (sum < m) {
			e++;
			sum += arr[e];
		}
	}

	if (min_len == MAX)
		min_len = 0;
	cout << min_len << endl;

	return 0;
}