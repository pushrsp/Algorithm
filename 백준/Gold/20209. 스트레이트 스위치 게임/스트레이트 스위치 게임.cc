#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
#include <set>
#include <algorithm>

#define ll long long
#define INF 1e9

using namespace std;

int N, K;

string get_visit(vector<int> &v) {
    string ret;
    for (auto &i: v)
        ret += to_string(i);

    return ret;
}

bool is_done(vector<int> &v) {
    int a = v[0];
    for (auto &i: v) {
        if (i != a)
            return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;

    vector<int> v(N);
    for (int n = 0; n < N; ++n)
        cin >> v[n];

    vector<vector<int>> s(K);
    for (int i = 0, n; i < K; ++i) {
        cin >> n;

        int x;
        for (int j = 0; j < n; ++j) {
            cin >> x;
            s[i].push_back(x - 1);
        }
    }

    queue<pair<vector<int>, int>> q;
    set<string> visited;

    visited.insert(get_visit(v));
    q.emplace(v, 0);

    int ret = 0;
    bool done = false;
    while (!q.empty()) {
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            vector<int> cube = curr.first;
            int count = curr.second;

            if (is_done(cube)) {
                done = true;
                ret = count;
                break;
            }

            for (int k = 0; k < K; ++k) {
                vector<int> copy(cube.begin(), cube.end());
                for (auto &n: s[k]) {
                    copy[n] += k + 1;
                    copy[n] %= 5;
                }

                string visit = get_visit(copy);
                if (visited.find(visit) != visited.end())
                    continue;

                visited.insert(visit);
                q.emplace(copy, count + 1);
            }
        }

        if (done)
            break;
    }

    if (!done)
        cout << -1 << '\n';
    else
        cout << ret << '\n';

    return 0;
}