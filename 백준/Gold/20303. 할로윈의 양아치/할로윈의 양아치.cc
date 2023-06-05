#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N, M, K, Arr[30001], DP[30001];
bool Visited[30001];
vector<int> Adj[30001];

void go(int &depth, int &sum, int curr) {
    Visited[curr] = true;
    depth++;
    sum += Arr[curr];

    for (auto &next: Adj[curr]) {
        if (Visited[next])
            continue;

        go(depth, sum, next);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; ++i)
        cin >> Arr[i];

    int a, b;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b;

        Adj[a].push_back(b);
        Adj[b].push_back(a);
    }

    vector<pair<int, int>> scores;
    scores.emplace_back(-1, -1);

    int depth = 0, sum = 0;
    for (int i = 1; i <= N; ++i) {
        if (Visited[i])
            continue;

        go(depth, sum, i);
        if (depth < K)
            scores.emplace_back(depth, sum);

        depth = 0, sum = 0;
    }

    for (int i = 1; i < scores.size(); ++i) {
        int population = scores[i].first, count = scores[i].second;
        for (int j = K - 1; j - population >= 0; --j)
            DP[j] = max(DP[j], DP[j - population] + count);
    }

    cout << DP[K - 1] << '\n';

    return 0;
}