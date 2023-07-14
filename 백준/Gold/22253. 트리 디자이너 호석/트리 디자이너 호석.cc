#include <iostream>
#include <vector>
#include <cstring>

#define ll long long

using namespace std;

int N, Arr[100001], MOD = 1000000007;
vector<int> Adj[100001];
bool Visited[100001];

vector<ll> go(int curr) {
    Visited[curr] = true;
    vector<ll> ret(10);

    ret[Arr[curr]] += 1;
    for (auto &next: Adj[curr]) {
        if (Visited[next])
            continue;

        vector<ll> result = go(next);
        for (int i = 0; i < 10; ++i) {
            ret[i] += result[i];
            if (i >= Arr[curr])
                ret[Arr[curr]] += result[i];

            ret[i] %= MOD;
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    for (int n = 1; n <= N; ++n)
        cin >> Arr[n];

    int a, b;
    for (int n = 0; n < N - 1; ++n) {
        cin >> a >> b;

        Adj[a].push_back(b);
        Adj[b].push_back(a);
    }

    vector<ll> result = go(1);
    ll ret = 0;

    for (ll &ans: result) {
        ret += ans;
        ret %= MOD;
    }

    cout << ret << '\n';

    return 0;
}