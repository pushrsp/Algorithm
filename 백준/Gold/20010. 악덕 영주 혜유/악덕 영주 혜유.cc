#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
#define MAX 1001

using namespace std;

struct Node {
    int n1, n2, dist;
};

int Q;
ll N, K, R;
int P1[MAX];
vector<pair<int, int>> Adj[MAX];
bool Visited[MAX];

bool cmp1(const Node &a, const Node &b) {
    return a.dist < b.dist;
}

int GetParent(int i) {
    if (P1[i] == i)
        return i;

    return P1[i] = GetParent(P1[i]);
}

void Union(int a, int b) {
    a = GetParent(a), b = GetParent(b);

    if (a < b)
        P1[b] = a;
    else
        P1[a] = b;
}

void go(int node, ll sum) {
    if (R < sum) {
        R = sum;
        Q = node;
    }

    for (auto &p: Adj[node]) {
        if (!Visited[p.first]) {
            Visited[p.first] = true;
            go(p.first, sum + p.second);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        P1[i] = i;

    vector<Node> v1;

    int n1, n2, dist;
    for (int i = 0; i < K; ++i) {
        cin >> n1 >> n2 >> dist;

        v1.push_back({n1, n2, dist});
    }

    sort(v1.begin(), v1.end(), cmp1);

    ll r1 = 0;
    for (auto &v: v1) {
        if (GetParent(v.n1) != GetParent(v.n2)) {
            r1 += v.dist;
            Union(v.n1, v.n2);

            Adj[v.n1].emplace_back(v.n2, v.dist);
            Adj[v.n2].emplace_back(v.n1, v.dist);
        }
    }

    Visited[0] = true;
    go(0, 0);

    fill(Visited, Visited + MAX, false);
    Visited[Q] = true;
    go(Q, 0);

    cout << r1 << '\n';
    cout << R << '\n';
    return 0;
}