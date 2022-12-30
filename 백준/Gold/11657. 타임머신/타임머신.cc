#include <iostream>
#include <queue>
#include <vector>
#include <sstream>

#define MAX 501
#define INF 987654321
#define ll long long

using namespace std;

struct City {
    int from, to, cost;
};

ll N, M, Dist[MAX];
vector<City> Cities;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    int a, b, c;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b >> c;

        Cities.push_back({a, b, c});
    }

    fill(Dist, Dist + MAX, INF);
    Dist[1] = 0;

    for (int i = 1; i <= N - 1; ++i) {
        for (City &city: Cities) {
            int from = city.from, to = city.to, cost = city.cost;

            if (Dist[from] == INF)
                continue;
            if (Dist[to] > Dist[from] + cost)
                Dist[to] = Dist[from] + cost;
        }
    }

    for (City &city: Cities) {
        int from = city.from, to = city.to, cost = city.cost;

        if (Dist[from] == INF)
            continue;
        if (Dist[to] > Dist[from] + cost) {
            cout << -1 << '\n';
            return 0;
        }
    }

    for (int i = 2; i <= N; ++i) {
        if (Dist[i] == INF)
            cout << -1 << '\n';
        else
            cout << Dist[i] << '\n';
    }

    return 0;
}