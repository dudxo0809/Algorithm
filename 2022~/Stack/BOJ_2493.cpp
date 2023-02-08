/*

	BOJ_2493
	https://www.acmicpc.net/problem/2493

*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;


int n;

stack<pair<int,int>> MyStack;	// <index, value>
vector<int> MyVector;


void Input();


int main() {

	Input();

	
	for (int i = 0; i < n; i++) {

		if (MyStack.empty()) {
			MyStack.push(make_pair(i+1, MyVector[i]));
			cout << "0 ";
			continue;
		}

		if (MyStack.top().second > MyVector[i]) {
			cout << MyStack.top().first << " ";
			MyStack.push(make_pair(i+1, MyVector[i]));
		}
		else {
			while (!MyStack.empty()) {
				if (MyStack.top().second < MyVector[i]) {
					MyStack.pop();

				}
				else {
					cout << MyStack.top().first << " ";
					MyStack.push(make_pair(i+1, MyVector[i]));
					break;
				}
			}
			if (MyStack.empty()) {
				MyStack.push(make_pair(i+1, MyVector[i]));
				cout << "0 ";
			}
		}
	}



	return 0;
}

void Input()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		MyVector.push_back(temp);
	}
}
