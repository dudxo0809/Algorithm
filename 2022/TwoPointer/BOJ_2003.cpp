#include <iostream>
using namespace std;


int n, m;
int arr[10000];

int s = 0;
int e = 0;

int sum = 0;
int cnt = 0;

int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}


	while (s < n && e < n) {
		sum = 0;
		for (int i = s; i <= e; i++) {
			sum += arr[i];
		}
		if (sum == m) {
			cnt++;
			s++;
		}
		else if (sum > m) {
			s++;
		}
		else
			e++;
	}


	cout << cnt << endl;



	return 0;
}