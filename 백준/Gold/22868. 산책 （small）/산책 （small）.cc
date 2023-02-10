#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 10001

using namespace std;

int N, M, S, E;
vector<int> Adj[MAX];
int Visited[MAX], History[MAX];

void Fill() {
    for (int i = 0; i <= N; ++i)
        Visited[i] = 0;

    int cur = E;
    while (History[cur] != cur) {
        Visited[cur] = 1;
        cur = History[cur];
    }

    Visited[S] = 1;
}

int BFS(int start, int end) {
    queue<pair<int, int>> pq;

    History[start] = start;
    Visited[start] = 1;
    pq.emplace(0, start);

    while (!pq.empty()) {
        int cur_node = pq.front().second;
        int cur_dist = pq.front().first;
        pq.pop();

        for (int &next: Adj[cur_node]) {
            if (!Visited[next]) {
                Visited[next] = 1;
                History[next] = cur_node;
                pq.emplace(cur_dist + 1, next);
            }

            if (next == end)
                return cur_dist + 1;
        }
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    int a, b;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b;

        Adj[a].push_back(b);
        Adj[b].push_back(a);
    }

    for (int i = 1; i <= N; ++i)
        sort(Adj[i].begin(), Adj[i].end());

    cin >> S >> E;

    int ret = BFS(S, E);
    Fill();
    ret += BFS(E, S);

    cout << ret << '\n';
    return 0;
}