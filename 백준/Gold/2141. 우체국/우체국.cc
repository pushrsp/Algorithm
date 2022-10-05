#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int N;

/*
3
1 7
2 3
3 1
answer = 1;

3
1 7
2 2
3 8
answer = 2;
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    ll total = 1;
    vector<pair<ll, ll>> vec(N);
    for (int n = 0; n < N; ++n) {
        cin >> vec[n].first >> vec[n].second;
        total += vec[n].second;
    }

    sort(vec.begin(), vec.end());

    ll sum = 0;
    for (int n = 0; n < N; ++n) {
        sum += vec[n].second;

        if (sum >= total / 2) {
            cout << vec[n].first << '\n';
            break;
        }
    }
    return 0;
}