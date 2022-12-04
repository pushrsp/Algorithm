#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

int N, K, M;
vector<int> Stations[100001];
vector<int> Tubes[1001];
bool Visited[100001];

int bfs() {
    queue<pair<int, int>> q;

    Visited[1] = true;
    q.emplace(1, 1);

    while (!q.empty()) {
        auto now = q.front();
        q.pop();

        if (now.first == N)
            return now.second;

        for (int &tube: Stations[now.first]) {
            for (int &next: Tubes[tube]) {
                if (Visited[next])
                    continue;

                q.emplace(next, now.second + 1);
                Visited[next] = true;

            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K >> M;

    int station;
    for (int i = 1; i <= M; ++i) {
        for (int j = 0; j < K; ++j) {
            cin >> station;

            Stations[station].push_back(i);
            Tubes[i].push_back(station);
        }
    }

    cout << bfs() << '\n';
    return 0;
}