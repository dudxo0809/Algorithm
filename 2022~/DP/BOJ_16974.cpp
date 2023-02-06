#include <iostream>
using namespace std;

int n;
long long int x;

long long int burger[51];
long long int patty[51];

void Input();
void InitializeArray();

long long int GetNumOfPattiesAte(int n, long long int x);

int main() {

	Input();

	InitializeArray();


	cout << GetNumOfPattiesAte(n, x) << endl;



	return 0;
}

void Input()
{
	cin >> n >> x;
}

void InitializeArray()
{
	burger[0] = 1;
	patty[0] = 1;
	for (int i = 1; i <= 50; i++) {
		burger[i] = 2 * burger[i - 1] + 3;
		patty[i] = 2 * patty[i - 1] + 1;
	}
}

// Has 5 different cases
long long int GetNumOfPattiesAte(int n, long long int x)
{
	if (n == 0)	// A patty
		return x;
	if (x == 1)	// A burger bun
		return 0;
	else if (x <= 1 + burger[n - 1])
		return GetNumOfPattiesAte(n - 1, x - 1);
	else if (x == 2 + burger[n - 1])
		return patty[n - 1] + 1;
	else if (x <= 2 + 2 * burger[n - 1])
		return patty[n - 1] + 1 + GetNumOfPattiesAte(n - 1, x - (2 + burger[n - 1]));
	else
		return 1 + 2 * patty[n - 1];
}
