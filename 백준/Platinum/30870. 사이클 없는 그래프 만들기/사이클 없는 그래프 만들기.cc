#include <iostream>
#include <queue>
#include <set>
#include <algorithm>

#define INF 987654321

using namespace std;

struct Info {
    int w, u, v;
};

int N, M, K, Parent[200001], InActive[200001];
vector<int> Adj[200001];

bool desc(const Info &a, const Info &b) {
    return a.w > b.w;
}

int get_parent(int n) {
    if (n == Parent[n])
        return n;

    return Parent[n] = get_parent(Parent[n]);
}

void merge(int a, int b) {
    a = get_parent(a), b = get_parent(b);

    if (a < b)
        Parent[b] = a;
    else
        Parent[a] = b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> K;

    for (int n = 0; n <= N; ++n)
        Parent[n] = n;

    set<pair<int, int>> s;
    vector<pair<int, int>> vec;

    int u, v;
    for (int m = 0; m < M; ++m) {
        cin >> u >> v;

//        if (s.find(make_pair(u, v)) != s.end())
//            continue;
//        if (s.find(make_pair(v, u)) != s.end())
//            continue;

        Adj[u].push_back(v);
        Adj[v].push_back(u);

        vec.emplace_back(u, v);

//        s.insert(make_pair(u, v));
//        s.insert(make_pair(v, u));
    }

    queue<int> q;

    int node;
    for (int k = 0; k < K; ++k) {
        cin >> node;

        q.push(node);
        InActive[node] = 1;
    }

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        for (auto &next: Adj[curr]) {
            if (InActive[next] > 0)
                continue;

            InActive[next] = InActive[curr] + 1;
            q.push(next);
        }
    }

    vector<Info> info;
    info.resize(vec.size());
    for (auto &p: vec)
        info.push_back({min(InActive[p.first], InActive[p.second]), p.first, p.second});

    sort(info.begin(), info.end(), desc);

    for (auto &i: info) {
        if (get_parent(i.u) != get_parent(i.v)) {
            merge(i.u, i.v);
        } else {
            cout << i.w << '\n';
            return 0;
        }
    }

    cout << 0 << '\n';

    return 0;
}