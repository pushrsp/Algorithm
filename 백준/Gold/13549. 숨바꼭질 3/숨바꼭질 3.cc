#include <iostream>
#include <deque>
#include <algorithm>

#define INF 987654321

using namespace std;

int N, K, Dist[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;

    deque<int> dq;
    dq.push_back(N);

    ::fill(Dist, Dist + 100001, INF);
    Dist[N] = 0;

    while (!dq.empty()) {
        int curr = dq.front();
        dq.pop_front();

        if (curr == K) {
            cout << Dist[K] << '\n';
            return 0;
        }

        int tp = curr * 2;
        if (tp <= 100000 && Dist[tp] > Dist[curr]) {
            Dist[tp] = Dist[curr];
            dq.push_front(tp);
        }

        int l = curr - 1, r = curr + 1;
        if (l >= 0 && Dist[l] > Dist[curr] + 1) {
            Dist[l] = Dist[curr] + 1;
            dq.push_back(l);
        }

        if (r <= 100000 && Dist[r] > Dist[curr] + 1) {
            Dist[r] = Dist[curr] + 1;
            dq.push_back(r);
        }
    }
    return 0;
}