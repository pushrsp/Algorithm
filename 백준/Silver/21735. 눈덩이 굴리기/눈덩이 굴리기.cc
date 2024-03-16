#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <map>

#define ll long long

using namespace std;

struct P {
    int n, m;
    ll size;

    bool operator<(const P &other) const {
        return size < other.size;
    }
};

int N, M, A[103];

void bfs() {
    queue<P> q;
    q.push({0, 0, 1});

    ll ret = 0;
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        int n = curr.n, m = curr.m;
        ll size = curr.size;
        if (n >= N || m >= M) {
            ret = max(ret, size);
            continue;
        }

        q.push({n + 1, m + 1, size + A[n + 1]});
        q.push({n + 2, m + 1, (size / 2) + A[n + 2]});
    }

    cout << ret << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;
    for (int n = 1; n <= N; ++n)
        cin >> A[n];

    bfs();
    return 0;
}