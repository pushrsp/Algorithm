#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

#define MAX 1001

using namespace std;

struct Node {
    double dist;
    int y, x;

    bool operator<(const Node &other) const {
        return dist < other.dist;
    }
};

int N, M, Parent[MAX];
vector<pair<int, int>> Coord;
vector<pair<int, int>> Connected;
vector<Node> Dist;

int GetParent(int x) {
    if (Parent[x] == x)
        return x;

    return Parent[x] = GetParent(Parent[x]);
}

void Union(int a, int b) {
    a = GetParent(a), b = GetParent(b);

    if (a < b)
        Parent[b] = a;
    else
        Parent[a] = b;
}

double GetDist(int y1, int x1, int y2, int x2) {
    return ::sqrt(::pow(y1 - y2, 2) + ::pow(x1 - x2, 2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    Coord = vector<pair<int, int>>(N);
    Connected = vector<pair<int, int>>(M);

    for (int i = 1; i <= N; ++i)
        Parent[i] = i;

    for (int i = 0; i < N; ++i)
        cin >> Coord[i].first >> Coord[i].second;
    for (int i = 0; i < M; ++i)
        cin >> Connected[i].first >> Connected[i].second;

    for (auto &connected: Connected) {
        if (GetParent(connected.first) != GetParent(connected.second))
            Union(connected.first, connected.second);
    }

    for (int i = 0; i < N; ++i) {
        int y1 = Coord[i].first, x1 = Coord[i].second;

        for (int j = i + 1; j < N; ++j) {
            int y2 = Coord[j].first, x2 = Coord[j].second;

            Dist.push_back({GetDist(y1, x1, y2, x2), i + 1, j + 1});
        }
    }

    sort(Dist.begin(), Dist.end());

    double ret = 0;
    for (auto &dist: Dist) {
        if (GetParent(dist.y) != GetParent(dist.x)) {
            ret += dist.dist;
            Union(dist.y, dist.x);
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << ret << '\n';
    
    return 0;
}