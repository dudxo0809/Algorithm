#include <iostream>
#include <cstring>
using namespace std;

int n;
int arr[3];
int dp[180][180][180];

int cnt = 0;

void Input();

int Func(int a, int b, int c);

int main() {

	Input();

	cout << Func(arr[0], arr[1], arr[2]) << endl;


	return 0;
}

int Func(int a, int b, int c)
{
	int ret = 9999999;

	if (a < 0)return Func(0, b, c);
	if (b < 0)return Func(a, 0, c);
	if (c < 0)return Func(a, b, 0);

	if (a == 0 && b == 0 && c == 0)
		return 0;
	else {
		if (dp[a][b][c] != -1)
			return dp[a][b][c];

		ret = min(ret, Func(a - 9, b - 3, c - 1) + 1);
		ret = min(ret, Func(a - 9, b - 1, c - 3) + 1);
		ret = min(ret, Func(a - 3, b - 9, c - 1) + 1);
		ret = min(ret, Func(a - 3, b - 1, c - 9) + 1);
		ret = min(ret, Func(a - 1, b - 9, c - 3) + 1);
		ret = min(ret, Func(a - 1, b - 3, c - 9) + 1);
	}

	dp[a][b][c] = ret;

	return ret;
}

void Input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	memset(dp, -1, sizeof(dp));
}

