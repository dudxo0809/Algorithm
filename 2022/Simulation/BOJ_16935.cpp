#include <iostream>
using namespace std;

int n, m, r;
int arr[100][100];
int temp[100][100];

void Input();
void Print();
void Func(int mode);

int main() {

	Input();

	for (int i = 0; i < r; i++) {
		int num;
		cin >> num;
		Func(num);
	}

	Print();

	return 0;
}

void Input()
{
	cin >> n >> m >> r;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
}

void Print()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void Func(int mode)
{
	switch (mode) {
	case 1:	// up <-> down

		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < m; j++) {
				swap(arr[i][j], arr[n - i - 1][j]);
			}
		}
		break;
	case 2: // left <-> right

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m / 2; j++) {
				swap(arr[i][j], arr[i][m - j - 1]);
			}
		}

		break;
	case 3: // rotate right

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				temp[i][j] = arr[n - j - 1][i];
			}
		}
		swap(n, m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				arr[i][j] = temp[i][j];

		break;
	case 4:	// rotate left

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				temp[i][j] = arr[j][m - i - 1];
			}
		}
		swap(n, m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				arr[i][j] = temp[i][j];

		break;
	case 5://
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < m / 2; j++)
				temp[i][j + m / 2] = arr[i][j];
			for (int j = m / 2; j < m; j++)
				temp[i + n / 2][j] = arr[i][j];
		}
		for (int i = n / 2; i < n; i++) {
			for (int j = 0; j < m / 2; j++)
				temp[i - n / 2][j] = arr[i][j];
			for (int j = m / 2; j < m; j++)
				temp[i][j - m / 2] = arr[i][j];
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				arr[i][j] = temp[i][j];


		break;
	case 6: //

		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < m / 2; j++)
				temp[i + n / 2][j] = arr[i][j];
			for (int j = m / 2; j < m; j++)
				temp[i][j - m / 2] = arr[i][j];
		}
		for (int i = n / 2; i < n; i++) {
			for (int j = 0; j < m / 2; j++)
				temp[i][j + m / 2] = arr[i][j];
			for (int j = m / 2; j < m; j++)
				temp[i - n / 2][j] = arr[i][j];
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				arr[i][j] = temp[i][j];

		break;

	default:
		break;
	}
}
