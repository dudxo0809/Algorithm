#include <iostream>
#include <vector>
using namespace std;


class Matrix {
public:
	int y;
	int x;
	int mul;

	Matrix() {};
	Matrix(int y, int x, int m) :y(y), x(x), mul(m) {};
};

int n;
int temp[2];
vector<Matrix> v; // y, x

Matrix dp[500][500];

Matrix mm;
// i~j ±îÁö °ö¿¬»ê¿¡¼­ ÃÖ¼Ò°ª
//
// F(A, B) : A ¹­À½°ú B¹­À½ÀÇ °ö¿¬»ê È½¼ö
//  => dp[A] + dp[B]
// 
// dp[i][j] = min(F((0,0), (1,4)), F((0,1), (2,4)),F((0,2), (3,4)),F((0,3), (4,4)))
//			== min (dp[0][0] + dp[1][4]) ~ dp[0][3] + dp[4][4]
//			for(int i=0;i<=n-1;i++)
//				dp[0][i] + dp[i+1][n-1]
// 
// A, B, C, D, E
// 
// n : n-1¹ø ¹­¾î¼­ °ö¿¬»ê

Matrix GetMulVal(Matrix a, Matrix b) { // a * b

	Matrix ret;

	ret.x = b.x;
	ret.y = a.y;
	ret.mul = a.mul + b.mul + (a.y * a.x * b.x);

	return ret;
}

int main() { // dp[][] : i ~ j ±îÁö °ö¿¬»ê °á°ú! => ÃÖ¼Ú°ª 

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp[0] >> temp[1];
		v.emplace_back(temp[0], temp[1], 0);
	}
	for (int i = 0; i < n; i++) {
		Matrix m = { v[i].y, v[i].x, 0 };
		dp[i][i] = m;
	}

	for (int i = 2; i <= n; i++) { // window size
		for (int j = 0; j <= n - i; j++) { // start index
			Matrix min_mat = { 0,0,2147483647 };

			for (int k = 0; k < i - 1; k++) { // num_iteration // n=5 : 4, n=2 : 1
				mm = GetMulVal(dp[j][j + k], dp[j + k + 1][j + i - 1]);
				if (mm.mul < min_mat.mul)
					min_mat = mm;
			}

			dp[j][j + i - 1] = min_mat;
		}
	}
	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << dp[i][j].mul << " ";
		}
		cout << endl;
	}
	*/
	cout << dp[0][n - 1].mul << endl;


	return 0;
}

