#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>

#define MAX 1001
#define INF 987654321

using namespace std;

struct Node {
    int node, dist;
    bool valid;
};

struct Point {
    int node, dist, state;

    bool operator<(const Point &other) const {
        return dist > other.dist;
    }
};

bool Trap[MAX];
int Dest, TrapState[MAX], Dist[MAX][1 << 10];
vector<vector<Node>> Adj;

int On(int state, int node) {
    return state | (1 << TrapState[node]);
}

int Off(int state, int node) {
    return state ^ (1 << TrapState[node]);
}

bool GetActive(int node, int state) {
    return state & (1 << TrapState[node]);
}

int Di(int start, int dest) {
    priority_queue<Point> pq;

    Dist[start][0] = 0;
    pq.push({start, 0, 0});

    while (!pq.empty()) {
        int cur_node = pq.top().node;
        int cur_dist = pq.top().dist;
        int cur_state = pq.top().state;
        pq.pop();

        for (auto &next: Adj[cur_node]) {
            int next_node = next.node;
            int next_dist = next.dist + cur_dist;
            int next_state = cur_state;
            int next_valid = next.valid;

            if (!Trap[cur_node] && !Trap[next_node]) {
                if (next_valid) {
                    if (Dist[next_node][next_state] > next_dist) {
                        Dist[next_node][next_state] = next_dist;
                        pq.push({next_node, next_dist, next_state});
                    }
                }
            } else if (!Trap[cur_node] && Trap[next_node]) {
                bool is_active = GetActive(next_node, next_state);

                if (!is_active && next_valid) {
                    next_state = On(next_state, next_node);

                    if (Dist[next_node][next_state] > next_dist) {
                        Dist[next_node][next_state] = next_dist;
                        pq.push({next_node, next_dist, next_state});
                    }
                } else if (is_active && !next_valid) {
                    next_state = Off(next_state, next_node);

                    if (Dist[next_node][next_state] > next_dist) {
                        Dist[next_node][next_state] = next_dist;
                        pq.push({next_node, next_dist, next_state});
                    }
                }
            } else if (Trap[cur_node] && !Trap[next_node]) {
                bool is_active = GetActive(cur_node, cur_state);

                if (is_active && !next_valid) {
                    if (Dist[next_node][next_state] > next_dist) {
                        Dist[next_node][next_state] = next_dist;
                        pq.push({next_node, next_dist, next_state});
                    }
                } else if (!is_active && next_valid) {
                    if (Dist[next_node][next_state] > next_dist) {
                        Dist[next_node][next_state] = next_dist;
                        pq.push({next_node, next_dist, next_state});
                    }
                }
            } else {
                bool is_cur_active = GetActive(cur_node, cur_state);
                bool is_next_active = GetActive(next_node, next_state);

                if (is_cur_active == is_next_active && next_valid) {
                    next_state = is_next_active ? Off(next_state, next_node) : On(next_state, next_node);

                    if (Dist[next_node][next_state] > next_dist) {
                        Dist[next_node][next_state] = next_dist;
                        pq.push({next_node, next_dist, next_state});
                    }
                } else if (is_cur_active != is_next_active && !next_valid) {
                    next_state = is_next_active ? Off(next_state, next_node) : On(next_state, next_node);

                    if (Dist[next_node][next_state] > next_dist) {
                        Dist[next_node][next_state] = next_dist;
                        pq.push({next_node, next_dist, next_state});
                    }
                }
            }
        }
    }

    int ret = INF;
    for (int i = 0; i < (1 << 10); ++i)
        ret = min(ret, Dist[dest][i]);

    return ret;
}

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    Adj = vector<vector<Node>>(n + 1);

    for (auto &d1: Dist) {
        for (auto &d2: d1)
            d2 = INF;
    }

    for (int i = 0; i < traps.size(); ++i)
        Trap[traps[i]] = true, TrapState[traps[i]] = i;

    for (auto &road: roads) {
        Adj[road[0]].push_back({road[1], road[2], true});
        Adj[road[1]].push_back({road[0], road[2], false});
    }

    return Di(start, end);
}