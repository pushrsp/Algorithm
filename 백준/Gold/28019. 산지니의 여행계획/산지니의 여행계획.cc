#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>

#define ll long long

using namespace std;

struct Info {
    int a, b;
    ll c;
};

int N, M, S, P[50001];
vector<pair<int, ll>> G[50001];
ll Q[50001], R;

int get_parent(int n) {
    if (n == P[n])
        return n;

    return P[n] = get_parent(P[n]);
}

void merge(int a, int b) {
    a = get_parent(a), b = get_parent(b);

    if (a == b)
        return;

    if (a < b)
        P[b] = a;
    else
        P[a] = b;
}

bool desc(const Info &a, const Info &b) {
    return a.c > b.c;
}

ll go(int curr, int prev) {
    for (auto &next: G[curr]) {
        if (prev != next.first) {
            Q[curr] = max(Q[curr], go(next.first, curr) + next.second);
            R += next.second * 2;
        }
    }

    return Q[curr];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    vector<Info> vec(M);
    for (int m = 0; m < M; ++m)
        cin >> vec[m].a >> vec[m].b >> vec[m].c;

    sort(vec.begin(), vec.end(), desc);

    for (int n = 1; n <= N; ++n)
        P[n] = n;

    for (auto &info: vec) {
        if (get_parent(info.a) != get_parent(info.b)) {
            merge(info.a, info.b);

            G[info.a].emplace_back(info.b, info.c);
            G[info.b].emplace_back(info.a, info.c);
        }
    }

    cin >> S;

    go(S, S);

    cout << R - Q[S] << '\n';

    return 0;
}