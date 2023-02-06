#include <iostream>
#include <vector>
using namespace std;

#define MAX		9999999

int n, k;
int dp[10001];

vector<int> coin;

void Input();
void Func();

int main() {

	Input();

	Func();

	cout << (dp[k] == MAX ? -1 : dp[k]) << endl;

	return 0;
}

void Input() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		coin.push_back(temp);
	}
	for (int i = 1; i <= k; i++)
		dp[i] = MAX;
}
// 동전의 가짓수만큼 순회
// 내부적으로 최소값동전~목표가격까지 순회
//
// 순회방법?
// 
// 가장 작은값의 동전을 먼저 순회하고
// 점점 동전값을 키워가며 순회
// 
// dp[0] = 0 으로 시작!
// 
// 만약 동전값과 K가 같다면
// -> dp[j-coin[i]] 가 0이므로
// -> dp[j] = 1이 된다!!!
//
void Func() {

	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}
}