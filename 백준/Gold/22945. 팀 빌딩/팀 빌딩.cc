#include <iostream>
#include <set>
#include <vector>
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

    ll ret = 0;
    int left = 0, right = N - 1;
    while (left < right) {
        ll sum = (right - left - 1) * min(vec[left], vec[right]);

        if (vec[left] < vec[right])
            left++;
        else
            right--;
        ret = max(ret, sum);
    }

    cout << ret << '\n';

    return 0;
}