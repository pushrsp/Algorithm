#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

#define ll long long

using namespace std;

int N, K;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;

    vector<int> vec(N);
    for (int n = 0; n < N; ++n)
        cin >> vec[n];

    int prev = vec[0] + K, ret = 1;
    for (int n = 1; n < N; ++n) {
        if (vec[n] > prev) {
            ret += 1;
            prev = vec[n] + K;
        }
    }

    cout << ret << '\n';

    return 0;
}