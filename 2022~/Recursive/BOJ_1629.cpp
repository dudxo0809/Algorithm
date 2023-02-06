#include <iostream>
using namespace std;

long long int a, b, c;

long long int DevideAndConquer(int num) {
	if (num == 1)
		return a % c;

	long long int temp = (DevideAndConquer(num / 2) % c);

	if (num % 2 == 0)
		return (temp * temp) % c;
	else
		return ((temp * temp) % c * a) % c;
}

int main() {

	cin >> a >> b >> c;

	cout << DevideAndConquer(b) << endl;

	return 0;
}