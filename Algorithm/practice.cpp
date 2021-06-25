//----------------------------------//
// K¹øÂ° ¼ö                         //
//----------------------------------//


#include <string>
#include <vector>
#include <algorithm>


using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    int i, j, k;

    for (auto iter = commands.begin(); iter != commands.end(); ++iter) {
        i = (*iter)[0];
        j = (*iter)[1];
        k = (*iter)[2];

        vector<int> temp;
        for (int n = i - 1; n < j; n++) {
            temp.push_back(array[n]);
        }
        sort(temp.begin(), temp.end());
        answer.push_back(temp[k - 1]);
    }


    return answer;
}