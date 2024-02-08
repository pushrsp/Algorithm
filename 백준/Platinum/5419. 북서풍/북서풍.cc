#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>

#define ll long long

using namespace std;

int T, N, Seg[300001];
vector<pair<int, int>> Vec;
vector<int> VecY;

bool cmp_y(const int &a, const int &b) {
    return a > b;
}

bool cmp_pair(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first)
        return a.second > b.second;

    return a.first < b.first;
}

int query(int node, int s, int e, int l, int r) {
    if (s > r || e < l)
        return 0;
    if (l <= s && e <= r)
        return Seg[node];

    int mid = (s + e) / 2;
    return query(node * 2, s, mid, l, r) + query(node * 2 + 1, mid + 1, e, l, r);
}

void update(int node, int s, int e, int target) {
    if (s > target || e < target)
        return;
    if (s == e) {
        Seg[node] += 1;
        return;
    }

    int mid = (s + e) / 2;
    update(node * 2, s, mid, target);
    update(node * 2 + 1, mid + 1, e, target);
    Seg[node] = Seg[node * 2] + Seg[node * 2 + 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> N;

        Vec.clear();
        VecY.clear();
        ::memset(Seg, 0, sizeof(Seg));

        int x, y;
        for (int n = 0; n < N; ++n) {
            cin >> x >> y;
            Vec.emplace_back(x, y);
            VecY.push_back(y);
        }

        sort(VecY.begin(), VecY.end(), cmp_y);
        VecY.erase(unique(VecY.begin(), VecY.end()), VecY.end());
        
        sort(Vec.begin(), Vec.end(), cmp_pair);

        map<int, int> rank;
        for (int i = 0; i < VecY.size(); ++i)
            rank[VecY[i]] = i;

        ll ret = 0;
        for (int n = 0; n < N; ++n) {
            x = Vec[n].first, y = Vec[n].second;
            ret += query(1, 0, N - 1, 0, rank[y]);
            update(1, 0, N - 1, rank[y]);
        }

        cout << ret << '\n';
    }

    return 0;
}