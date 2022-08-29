#include<iostream>
#include<algorithm>
#include <vector>

using namespace std;

#define ll long long

int K, N;

int main() {
    cin >> K >> N;

    vector<ll> lan(K);
    for (int k = 0; k < K; ++k)
        cin >> lan[k];

    sort(lan.begin(), lan.end());

    ll left = 1, right = lan.back(), mid = 0, answer = 0;
    while (left <= right) {
        mid = (left + right) / 2;
        int cnt = 0;
        for (ll l: lan)
            cnt += l / mid;

        if (cnt >= N) {
            left = mid + 1;
            answer = mid;
        } else {
            right = mid - 1;
        }
    }

    cout << answer << endl;
    return 0;
}