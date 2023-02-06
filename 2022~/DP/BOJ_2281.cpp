#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;

int name[1000];
int dp[1000][1000];


int Func(int idx, int len);

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> name[i];
	}

	memset(dp, -1, sizeof(dp));

	cout << Func(0, 0) << endl;


	return 0;
}

int Func(int idx, int len)
{
	if (idx == n)
		return 0;

	int& ret = dp[idx][len];
	if (ret != -1)
		return ret;

	ret = (m - len + 1) * (m - len + 1) + Func(idx + 1, name[idx] + 1);
	if (len + name[idx] <= m)
		ret = min(ret, Func(idx + 1, len + name[idx] + 1));

	return ret;

}
