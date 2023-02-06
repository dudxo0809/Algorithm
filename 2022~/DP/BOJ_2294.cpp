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
// ������ ��������ŭ ��ȸ
// ���������� �ּҰ�����~��ǥ���ݱ��� ��ȸ
//
// ��ȸ���?
// 
// ���� �������� ������ ���� ��ȸ�ϰ�
// ���� �������� Ű������ ��ȸ
// 
// dp[0] = 0 ���� ����!
// 
// ���� �������� K�� ���ٸ�
// -> dp[j-coin[i]] �� 0�̹Ƿ�
// -> dp[j] = 1�� �ȴ�!!!
//
void Func() {

	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}
}