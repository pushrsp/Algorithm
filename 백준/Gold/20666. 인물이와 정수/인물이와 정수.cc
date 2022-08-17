#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define ll long long

int N, M, P;

int main() {
    cin >> N >> M;

    vector<ll> monsters(N + 1);
    vector<vector<pair<ll, ll>>> items(N + 1);
    vector<bool> visited(N + 1, false);

    for (int n = 1; n <= N; ++n)
        cin >> monsters[n];

    cin >> P;
    for (int p = 0; p < P; ++p) {
        int a, b, t;
        cin >> a >> b >> t;

        monsters[b] += t;
        items[a].emplace_back(b, t);
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    for (int n = 1; n <= N; ++n)
        pq.push({monsters[n], n});

    ll answer = 0;
    while (M > 0) {
        auto monster = pq.top();
        pq.pop();

        if (visited[monster.second])
            continue;

        visited[monster.second] = true;

        for (auto &item: items[monster.second]) {
            if (visited[item.first])
                continue;

            monsters[item.first] -= item.second;
            pq.push({monsters[item.first], item.first});
        }

        answer = max(answer, monster.first);
        M--;
    }

    cout << answer << endl;

    return 0;
}