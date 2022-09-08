#include <iostream>
using namespace std;

void Func(int i, int j, int n) {

	if (n == 1) {
		cout << "*";
	}
	else if ((i / (n / 3)) % 3 == 1 && (j / (n / 3)) % 3 == 1) {
		cout << " ";
	}
	else
		Func(i, j, n / 3);
}

int main() {

	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			Func(i, j, num);
		}
		cout << endl;
	}


	return 0;
}