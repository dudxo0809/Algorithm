#include <iostream>
using namespace std;

int n;

int arr[1000];
int dp_in[1000];
int dp_de[1000];

void Input();
int DP();

int main() {

	Input();

	cout << DP() << endl;

	return 0;
}

void Input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp_in[i] = 1;
		dp_de[i] = 1;
	}
}

// DP 현재 값을 가운데로놓고 수열길이? => 안됨

// 1 2 2 1 3 3 4 5 2 1 : 정방향
// 1 5 2 1 4 3 3 3 2 1 : 역방향 dp (감소수열)
// 두개 dp합 -1 : 가장 큰값
// dp값의 합이 가장 큰 원소가 수열의 가운데값

// 1 1
// 2 1
// 2 1

int DP() {

	int ret = 0;

	for (int i = 0; i < n; i++) {
		int max_dp = 0;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				if (dp_in[j] > max_dp)
					max_dp = dp_in[j];
			}
		}
		dp_in[i] = max_dp + 1;
	}

	for (int i = n - 1; i >= 0; i--) {
		int max_dp = 0;
		for (int j = n - 1; j > i; j--) {
			if (arr[j] < arr[i]) {
				if (dp_de[j] > max_dp)
					max_dp = dp_de[j];
			}
		}
		dp_de[i] = max_dp + 1;
	}


	for (int i = 0; i < n; i++) {
		ret = (dp_in[i] + dp_de[i] > ret ? dp_in[i] + dp_de[i] : ret);
	}
	ret--;

	return ret;
}
