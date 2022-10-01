#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    vector<pair<int, int>> cows(N);
    for (int n = 0; n < N; ++n)
        cin >> cows[n].first >> cows[n].second;

    sort(cows.begin(), cows.end());
    int prev = 0;
    for (int n = 0; n < N; ++n) {
        if (prev < cows[n].first)
            prev = cows[n].first + cows[n].second;
        else
            prev += cows[n].second;
    }

    cout << prev << '\n';
    return 0;
}