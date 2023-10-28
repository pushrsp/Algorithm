#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define ll long long

using namespace std;

struct Ing {
    ll s, l;
    int o;
};

int N, K;
ll G;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> G >> K;

    vector<Ing> vec(N);
    for (int n = 0; n < N; ++n)
        cin >> vec[n].s >> vec[n].l >> vec[n].o;

    ll left = 0, right = 1e9 * 2, mid, cap, ret = 0;
    while (left <= right) {
        mid = (left + right) / 2;
        cap = 0;

        priority_queue<ll> pq;
        for (int n = 0; n < N; ++n) {
            ll sum = vec[n].s * max((ll) 1, mid - vec[n].l);
            cap += sum;

            if (vec[n].o)
                pq.push(sum);
        }

        if (cap > G) {
            int k = 0;
            while (!pq.empty() && k < K) {
                cap -= pq.top();
                pq.pop();
                k++;
            }
        }

        if (cap <= G) {
            ret = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << ret << '\n';

    return 0;
}