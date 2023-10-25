#include <iostream>
#include <vector>
#include <algorithm>

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

    vector<ll> ans(2);
    ll ret = INT64_MAX;
    int left = 0, right = N - 1;
    while (left < right) {
        ll sum = vec[left] + vec[right];

        if (abs(sum) < ret) {
            ret = abs(sum);
            ans[0] = vec[left];
            ans[1] = vec[right];
        }

        if (sum < 0) {
            left++;
        } else if (sum == 0) {
            cout << vec[left] << ' ' << vec[right] << '\n';
            return 0;
        } else {
            right--;
        }
    }

    cout << ans[0] << ' ' << ans[1] << '\n';
    
    return 0;
}