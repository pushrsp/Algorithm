#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <algorithm>

#define ll long long
#define INF 987654321

using namespace std;

int N, M, H, A[11][11], Ans;
pair<int, int> S;
vector<pair<int, int>> Milks;
bool Visited[12];

int dist(pair<int, int> &a, pair<int, int> &b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void go(pair<int, int> curr, int hp, int milk) {
    if (dist(curr, S) <= hp)
        Ans = max(Ans, milk);

    for (int i = 0; i < Milks.size(); ++i) {
        if (Visited[i])
            continue;

        Visited[i] = true;
        if (hp - dist(curr, Milks[i]) >= 0)
            go(Milks[i], hp - dist(curr, Milks[i]) + H, milk + 1);

        Visited[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> H;

    for (int y = 1; y <= N; ++y) {
        for (int x = 1; x <= N; ++x) {
            cin >> A[y][x];

            if (A[y][x] == 1)
                S.first = y, S.second = x;
            else if (A[y][x] == 2)
                Milks.emplace_back(y, x);
        }
    }

    go(S, M, 0);

    cout << Ans << '\n';

    return 0;
}