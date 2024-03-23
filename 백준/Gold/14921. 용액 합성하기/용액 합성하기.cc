#include <cstring>
#include <vector>
#include <map>
#include <iostream>
#include <queue>
#include <algorithm>

#define ll long long
#define INF 1e9

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    vector<ll> v(N);
    for (int n = 0; n < N; ++n)
        cin >> v[n];

    ll ret = INT64_MAX, offset = INT64_MAX;
    int i = 0, j = N - 1;
    while (i < j) {
        if (offset > abs(v[i] + v[j])) {
            offset = abs(v[i] + v[j]);
            ret = v[i] + v[j];
        }

        if (v[i] + v[j] < 0)
            i++;
        else
            j--;
    }

    cout << ret << '\n';

    return 0;
}