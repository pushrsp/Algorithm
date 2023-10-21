#include <iostream>
#include <cstring>
#include <algorithm>

#define INF 1e18
#define ll long long

using namespace std;

int N;
ll K, Dist[105], Duration[105], DP[105], Sum[105];
vector<int> Nodes;

ll go(int curr) {
    if (curr >= N + 1)
        return 0;

    ll &ret = DP[curr];
    if (ret != -1)
        return ret;

    ret = INF;
    for (int i = curr + 1; i <= N + 1; ++i) {
        if (Sum[i] - Sum[curr] <= K)
            ret = min(ret, go(i) + Duration[i]);
    }

    return ret;
}

void trace(int curr) {
    if (curr >= N + 1)
        return;

    for (int i = curr + 1; i <= N + 1; ++i) {
        if (Sum[i] - Sum[curr] <= K) {
            if (DP[curr] - DP[i] == Duration[i]) {
                if (i != N + 1)
                    Nodes.push_back(i);

                trace(i);
                break;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> K;
    cin >> N;

    for (int n = 1; n <= N + 1; ++n) {
        cin >> Dist[n];
        Sum[n] = Sum[n - 1] + Dist[n];
    }
    for (int n = 1; n <= N; ++n)
        cin >> Duration[n];

    ::memset(DP, -1, sizeof(DP));

    ll ret = go(0);
    if (ret >= INF) {
        cout << 0 << '\n';
    } else {
        cout << ret << '\n';
        trace(0);

        cout << Nodes.size() << '\n';
        for (auto &node: Nodes)
            cout << node << ' ';
        cout << '\n';
    }


    return 0;
}