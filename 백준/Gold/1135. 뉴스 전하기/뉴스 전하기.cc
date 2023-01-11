#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define MAX 51

using namespace std;

int N;
vector<vector<int>> Adj;

int go(int node) {
    int ret = 0;
    vector<int> candidate;

    for (auto &next: Adj[node])
        candidate.push_back(go(next));

    sort(candidate.begin(), candidate.end());

    int len = static_cast<int>(Adj[node].size() - 1);
    for (auto &cand: candidate)
        ret = max(ret, cand + len--);

    return ret + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    Adj = vector<vector<int>>(N);

    int parent;
    for (int i = 0; i < N; ++i) {
        cin >> parent;

        if (parent == -1)
            continue;

        Adj[parent].push_back(i);
    }

    cout << go(0) - 1 << '\n';
    return 0;
}