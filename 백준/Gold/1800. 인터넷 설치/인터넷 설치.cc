#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 1001
#define INF 987654321

using namespace std;

int N, P, K;
int Dist[MAX];
vector<pair<int, int>> Computers[MAX];

bool Di(int start, int mx) {
    priority_queue<pair<int, int>> pq;

    Dist[start] = 0;
    pq.emplace(0, start);

    while (!pq.empty()) {
        int cur = pq.top().second;
        int cost = -pq.top().first;

        pq.pop();

        for (auto &next: Computers[cur]) {
            int next_node = next.first;
            int next_cost = next.second;

            int c = cost + (next_cost > mx);
            if (Dist[next_node] > c) {
                Dist[next_node] = c;
                pq.emplace(-c, next_node);
            }
        }
    }

    return Dist[N] <= K;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> P >> K;

    int a, b, c;
    for (int i = 0; i < P; ++i) {
        cin >> a >> b >> c;

        Computers[a].emplace_back(b, c);
        Computers[b].emplace_back(a, c);
    }

    int left = 0, right = 1e7, mid, answer = -1;
    while (left <= right) {
        mid = (left + right) / 2;
        fill(Dist, Dist + MAX, INF);

        if (Di(1, mid)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer << '\n';
    return 0;
}