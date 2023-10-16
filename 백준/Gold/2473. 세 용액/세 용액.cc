#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    vector<ll> vec(N);
    for (int n = 0; n < N; ++n)
        cin >> vec[n];

    sort(vec.begin(), vec.end());

    ll ans = 1e18;
    vector<ll> ret(3);
    for (int n = 0; n < N - 2; ++n) {
        int left = n + 1, right = N - 1;
        while (left < right) {
            ll sum = vec[n] + vec[left] + vec[right];
            if (abs(sum) < ans) {
                ans = abs(sum);
                ret[0] = vec[n];
                ret[1] = vec[left];
                ret[2] = vec[right];
            }

            if (sum < 0)
                left++;
            else
                right--;
        }
    }

    cout << ret[0] << ' ' << ret[1] << ' ' << ret[2] << '\n';

    return 0;
}