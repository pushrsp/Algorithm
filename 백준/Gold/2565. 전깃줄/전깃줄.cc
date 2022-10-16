#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, Arr[501], Len;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    vector<pair<int, int>> vec(N);
    for (int n = 0; n < N; ++n)
        cin >> vec[n].first >> vec[n].second;

    sort(vec.begin(), vec.end());

    for (int i = 0; i < N; ++i) {
        auto iter = lower_bound(Arr, Arr + Len, vec[i].second);
        if (*iter == 0)
            Len++;

        *iter = vec[i].second;
    }

    cout << N - Len << '\n';

    return 0;
}