#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_set>

using namespace std;

int N, InDegree[28];
vector<int> Adj[28];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    unordered_set<char> visited;
    vector<string> vec(N);
    for (int i = 0; i < N; ++i) {
        cin >> vec[i];

        for (char &c: vec[i])
            visited.insert(c);
    }

    bool success = true;
    for (int i = 0; i < N - 1; ++i) {
        int len = min(vec[i].length(), vec[i + 1].length());

        for (int j = 0; j < len; ++j) {
            if (vec[i][j] != vec[i + 1][j]) {
                Adj[vec[i][j] - 'a'].push_back(vec[i + 1][j] - 'a');
                InDegree[vec[i + 1][j] - 'a']++;
                break;
            }

            if (j == len - 1 && vec[i].length() > vec[i + 1].length())
                success = false;
        }
    }

    if (!success) {
        cout << '!' << '\n';
        return 0;
    }

    queue<int> q;
    for (auto &p: visited) {
        if (InDegree[p - 'a'] == 0)
            q.push(p - 'a');
    }

    bool is_multi = false;
    vector<char> answer;
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        if (!q.empty())
            is_multi = true;

        answer.push_back((char) (curr + 'a'));

        for (int &next: Adj[curr]) {
            if (--InDegree[next] == 0)
                q.push(next);
        }
    }

    if (answer.size() != visited.size()) {
        cout << '!' << '\n';
    } else if (is_multi) {
        cout << '?' << '\n';
    } else {
        for (auto &ans: answer)
            cout << ans;
    }
    return 0;
}