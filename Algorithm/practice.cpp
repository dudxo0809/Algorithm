#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool Pred(int a, int b) {

    string temp1,temp2;

    string _a = to_string(a);
    string _b = to_string(b);
   
    temp1 += _a;
    temp1 += _b;

    temp2 += _b;
    temp2 += _a;

    return atoi(temp1.c_str()) > atoi(temp2.c_str());
}

string solution(vector<int> numbers) {

    string answer = "";

    sort(numbers.begin(), numbers.end(), Pred);
    for (auto iter = numbers.begin(); iter != numbers.end(); ++iter) {
        answer += to_string(*iter);
    }
    if (answer[0])
        return "0";

    return answer;
}

int main() {

    vector<int> v;

    for (int i = 0; i < 5; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    cout << solution(v);


    return 0;
}