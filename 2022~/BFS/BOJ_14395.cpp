// BOJ 14395

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int s, t;

int minus, div;

struct op {
	unsigned long long num;
	string ans;
};

int main() {

	cin >> s >> t;

	queue<op> q;
	q.push({s,""});
	while (!q.empty()) {
		unsigned long long a = q.front().num;
		string temp = q.front().ans;
		q.pop();

		if (a == t) {
			if(temp == "")
				cout << 0 << '\n';
			else
				cout << temp << '\n';
			return 0;
		}
		if (a * a <= t && a * a > 1);
			q.push({a*a,temp+'*'});
		if(a+a<=t&&a+a>0)
			q.push({ a + a,temp + '+' });
		if (minus == 0) {
			q.push({1,temp+'/'});
			div=1;
		}
		if (div = 1) {
			q.push({1,temp+'/'});
			div = 1;
		}
			
	}
	cout << -1 << endl;

	return 0;
}