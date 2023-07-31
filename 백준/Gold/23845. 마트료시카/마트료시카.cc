#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define ll long long
#define MAX 300002

using namespace std;

int N, Cnt[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    vector<ll> x(N);
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
        Cnt[x[i]]++;
    }

    sort(x.begin(), x.end());

    ll ret = 0;
    for (int i = 0; i < N; ++i) {
        if (Cnt[x[i]] == 0)
            continue;

        Cnt[x[i]]--;
        ll next = x[i] + 1, size = 1;
        while (Cnt[next] != 0) {
            Cnt[next]--;
            next++, size++;
        }

        ret += (next - 1) * (next - 1 - x[i] + 1);
    }

    cout << ret << '\n';

    return 0;
}