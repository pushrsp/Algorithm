#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int N, L;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L;

    vector<pair<int, int>> vec(N);
    for (int n = 0; n < N; ++n)
        cin >> vec[n].first >> vec[n].second;

    sort(vec.begin(), vec.end());

    int e = 0, answer = 0;
    for (int i = 0; i < N; ++i) {
        if (e >= vec[i].second)
            continue;

        if (e < vec[i].first) {
            int cnt = (vec[i].second - vec[i].first) / L + ((vec[i].second - vec[i].first) % L ? 1 : 0);
            e = vec[i].first + cnt * L;
            answer += cnt;
        } else {
            int cnt = (vec[i].second - e) / L + ((vec[i].second - e) % L ? 1 : 0);
            e += cnt * L;
            answer += cnt;
        }
    }

    cout << answer << '\n';
    return 0;
}