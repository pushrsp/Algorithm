#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

int N, C;

int main() {
    cin >> N >> C;

    vector<ll> house(N);
    for (int n = 0; n < N; ++n)
        cin >> house[n];

    sort(house.begin(), house.end());

    ll left = 0, right = house.back(), mid = 0, answer = 0;
    while (left <= right) {
        mid = (left + right) / 2;

        int wifi = 1;
        ll start = house[0];
        for (int i = 1; i < N; ++i) {
            if (house[i] - start >= mid) {
                wifi++;
                start = house[i];
            }
        }

        if (wifi >= C) {
            left = mid + 1;
            answer = mid;
        } else {
            right = mid - 1;
        }
    }

    cout << answer << endl;
    return 0;
}