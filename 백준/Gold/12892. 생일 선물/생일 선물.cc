#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long

using namespace std;

int N;
ll D;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> D;

    vector<pair<ll, ll>> vec(N);
    for (int n = 0; n < N; ++n)
        cin >> vec[n].first >> vec[n].second;

    sort(vec.begin(), vec.end());

    ll ret = 0, temp = 0;
    int left = 0, right = 0;
    while (left <= right && right < N) {
        if (vec[right].first - vec[left].first < D)
            temp += vec[right++].second;
        else
            temp -= vec[left++].second;

        ret = max(ret, temp);
    }

    cout << ret << '\n';
    return 0;
}