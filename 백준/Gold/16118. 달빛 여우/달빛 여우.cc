#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX 4001
#define INF 987654321

using namespace std;

int N, M;
vector<pair<int, int>> Adj[MAX];
int FD[MAX], WD[2][MAX];

void Di1() {
    priority_queue<pair<int, int>> pq;
    pq.emplace(0, 1);
    FD[1] = 0;

    while (!pq.empty()) {
        int curr_node = pq.top().second;
        int curr_cost = -pq.top().first;
        pq.pop();

        if (FD[curr_node] < curr_cost)
            continue;

        for (auto &next: Adj[curr_node]) {
            int next_node = next.first;
            int next_cost = curr_cost + next.second;

            if (FD[next_node] > next_cost) {
                FD[next_node] = next_cost;
                pq.emplace(-next_cost, next_node);
            }
        }
    }
}

void Di2() {
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.emplace(0, make_pair(1, 1));

    while (!pq.empty()) {
        int curr_node = pq.top().second.first;
        int curr_state = pq.top().second.second;
        int curr_cost = -pq.top().first;
        pq.pop();

        if (WD[(curr_state + 1) % 2][curr_node] < curr_cost)
            continue;

        for (auto &next: Adj[curr_node]) {
            int next_node = next.first;

            if (curr_state) {
                int next_cost = curr_cost + next.second / 2;

                if (WD[1][next_node] > next_cost) {
                    WD[1][next_node] = next_cost;
                    pq.emplace(-next_cost, make_pair(next_node, 0));
                }
            } else {
                int next_cost = curr_cost + next.second * 2;

                if (WD[0][next_node] > next_cost) {
                    WD[0][next_node] = next_cost;
                    pq.emplace(-next_cost, make_pair(next_node, 1));
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    int a, b, d;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b >> d;

        Adj[a].emplace_back(b, d * 2);
        Adj[b].emplace_back(a, d * 2);
    }

    for (int i = 0; i < MAX; ++i) {
        FD[i] = INF;
        WD[0][i] = INF;
        WD[1][i] = INF;
    }

    Di1();
    Di2();

    int ret = 0;
    for (int i = 2; i <= N; ++i) {
        if (FD[i] < min(WD[0][i], WD[1][i]))
            ret += 1;
    }

    cout << ret << '\n';

    return 0;
}