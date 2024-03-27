#include <cstring>
#include <vector>
#include <set>
#include <iostream>
#include <queue>
#include <algorithm>

#define ll long long
#define INF 1e9

using namespace std;

int N, P, E;

vector<int> get_bit_idx(int &n) {
    vector<int> ret;
    for (int i = 0; i < N; ++i) {
        if (n & (1 << i))
            ret.push_back(i);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> P >> E;

    vector<pair<int, int>> v(N);
    for (int n = 0; n < N; ++n)
        cin >> v[n].first >> v[n].second;

    int mx = 1 << N;
    for (int i = 0; i < mx; ++i) {
        vector<int> idx = get_bit_idx(i);
        if (idx.size() != P)
            continue;

        int e = 0, total = 0;
        queue<pair<int, int>> q;
        for (auto &id: idx) {
            q.emplace(v[id].first, id);
            e += v[id].first;
            total += v[id].second;
        }

        if (e == E) {
            vector<int> ret(N);
            for (auto &id: idx)
                ret[id] = v[id].first;

            for (auto &ans: ret)
                cout << ans << ' ';

            return 0;
        } else if (e > E) {
            continue;
        }

        while (!q.empty() && e < E) {
            auto curr = q.front();
            q.pop();

            if (e == total)
                break;

            int diff1 = v[curr.second].second - curr.first;
            int diff2 = min(E - e, diff1);
            e += diff2;
            q.emplace(curr.first + diff2, curr.second);
        }

        if (e == E) {
            vector<int> ret(N);
            while (!q.empty()) {
                auto curr = q.front();
                q.pop();

                ret[curr.second] = curr.first;
            }

            for (auto &ans: ret)
                cout << ans << ' ';

            return 0;
        }
    }

    cout << -1 << '\n';


    return 0;
}