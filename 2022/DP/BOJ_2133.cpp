#include <iostream>
using namespace std;

int n;

int dp[31] = { 0, };
// dp[6] = dp[4]*dp[2] + dp[2]*2 + dp[0]*2
// dp[0] : 빈칸을 채우는 경우의 수 : 타일을 하나도 안씀 : 1가지 경우
// dp[2] : 기본값 : 3
// dp[4] : 기본값 : 11
// dp[6] : 4칸 경우 * 2칸경우 + (4칸고유모양경우 * 2칸경우) +2
// dp[8] : 6칸경우 * 2칸경우 + (4칸고유모양경우*4칸경우) + (6칸고유모양경우 * 2칸경우) +2
// 각각의 경우에 고유모양이 있으므로 항상 +2를 해줌
int main() {

	cin >> n;
	if (n % 2 == 1) {
		cout << 0 << endl;
	}
	else {
		dp[0] = 1;
		dp[2] = 3;
		for (int i = 4; i <= n; i += 2) {
			dp[i] += dp[i - 2] * dp[2];
			for (int j = i - 4; j >= 0; j -= 2) {
				dp[i] += dp[j] * 2;
			}
		}
		cout << dp[n] << endl;
	}



	return 0;
}