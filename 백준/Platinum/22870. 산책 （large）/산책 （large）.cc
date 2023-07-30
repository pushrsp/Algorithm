#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 987654321

using namespace std;

int N, M, A, B, C, S, E, D1[200001], D2[200001], D3[200001];
vector<pair<int, int>> Adj[200001];
bool Visited[200001];

void Di(int s, int d[]) {
    priority_queue<pair<int, int>> pq;

    d[s] = 0;
    pq.emplace(0, s);

    while (!pq.empty()) {
        int cur_node = pq.top().second;
        int cur_dist = -pq.top().first;
        pq.pop();

        for (auto &next: Adj[cur_node]) {
            int next_node = next.first;
            int next_dist = next.second + cur_dist;

            if (Visited[next_node])
                continue;

            if (d[next_node] > next_dist) {
                d[next_node] = next_dist;
                pq.emplace(-next_dist, next_node);
            }
        }
    }
}

void go() {
    int prev = S;
    int s = S;

    while (s != E) {
        int min_node = INF;

        for (auto &next: Adj[s]) {
            int next_node = next.first;
            if (D1[s] + next.second + D2[next_node] == D1[E])
                min_node = min(min_node, next_node);
        }

        if (s != E)
            Visited[min_node] = true;

        prev = s;
        s = min_node;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;
    for (int m = 0; m < M; ++m) {
        cin >> A >> B >> C;

        Adj[A].emplace_back(B, C);
        Adj[B].emplace_back(A, C);
    }

    for (int n = 0; n <= N; ++n)
        sort(Adj[n].begin(), Adj[n].end());

    cin >> S >> E;

    ::fill(D1, D1 + 200001, INF);
    ::fill(D2, D2 + 200001, INF);
    ::fill(D3, D3 + 200001, INF);

    Di(S, D1);
    Di(E, D2);

    int ret = D1[E];
    go();

    Di(E, D3);
    ret += D3[S];

    cout << ret << '\n';

    return 0;
}