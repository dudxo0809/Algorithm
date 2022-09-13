#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;

int n_vowel;
int n_consonent;

vector<char> v;
vector<char> code;

vector<bool> visit;

void dfs(int cnt, int idx);

int main() {

    cin >> L >> C;
    for (int i = 0; i < C; i++) {
        char temp;
        cin >> temp;
        v.push_back(temp);
        visit.push_back(false);
    }
    sort(v.begin(), v.end());

    dfs(0, 0);

    return 0;
}



void dfs(int cnt, int idx) {

    if (cnt == L && n_vowel >= 1 && n_consonent >= 2) {
        for (auto i : code)
            cout << (char)i;
        cout << endl;
    }
    else {

        int start_idx = (code.empty() ? 0 : idx);

        for (int i = start_idx; i < v.size(); i++) {

            if (!visit[i]) {

                if (v[i] == 'a' || v[i] == 'u' || v[i] == 'o' || v[i] == 'i' || v[i] == 'e') {
                    n_vowel++;
                }
                else
                    n_consonent++;

                code.push_back(v[i]);
                visit[i] = true;

                dfs(cnt + 1, i);

                if (v[i] == 'a' || v[i] == 'u' || v[i] == 'o' || v[i] == 'i' || v[i] == 'e') {
                    n_vowel--;
                }
                else
                    n_consonent--;

                code.pop_back();
                visit[i] = false;
            }

        }
    }

}