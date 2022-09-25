#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

vector<int> Vec(9), Temp;
vector<vector<int>> Answer;

void dfs(int sum, int idx, int cnt) {
    if (sum > 100 || cnt > 7)
        return;

    if (cnt == 7 && sum == 100) {
        Answer.push_back(Temp);
        return;
    }

    for (int i = idx; i < 9; ++i) {
        Temp.push_back(Vec[i]);
        dfs(sum + Vec[i], i + 1, cnt + 1);
        Temp.pop_back();
    }
}

int main() {
    for (int i = 0; i < 9; ++i)
        cin >> Vec[i];

    dfs(0, 0, 0);
    if (!Answer.empty()) {
        sort(Answer[0].begin(), Answer[0].end());

        for (auto n: Answer[0])
            cout << n << endl;
    }
    return 0;
}