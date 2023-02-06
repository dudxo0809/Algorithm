#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

int n;
long long arr[100];

bool Check(long long int num) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == num)
			return true;
	}
	return false;
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++) {

		vector<long long int> v;
		v.push_back(arr[i]);
		bool flag = false;

		while (true) {
			if (v.size() == n) {
				flag = true;
				break;
			}
			bool flag2 = false;
			if (Check(v[v.size() - 1] * 2)) {
				flag2 = true;
				v.push_back(v[v.size() - 1] * 2);
			}
			if (!(v[v.size() - 1] % 3)) {
				if (Check(v[v.size() - 1] / 3)) {
					flag2 = true;
					v.push_back(v[v.size() - 1] / 3);
				}
			}
			if (flag2 == false)
				break;

		}
		if (flag == true) {
			for (auto j : v)
				cout << j << " ";
			return 0;
		}

	}



	return 0;
}