#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, K, S;

int get_dist(vector<pair<int, int>> &vec) {
    int seats = 0, dist = 0, prev = -1;

    while (!vec.empty()) {
        int p = vec.back().first, n = vec.back().second;
        int sum = seats + n;

        if (sum == K) {
            vec.pop_back();

            if (prev == -1) {
                dist += abs(S - p) * 2;
            } else {
                dist += prev * 2;
                prev = -1;
            }

            seats = 0;
            continue;
        }

        if (sum > K) {
            vec.back().second -= K - seats;
            seats = 0;

            if (prev == -1) {
                dist += abs(S - p) * 2;
            } else {
                dist += prev * 2;
                prev = -1;
            }
        } else {
            seats += n;
            vec.pop_back();
            prev = max(prev, abs(S - p));
        }

        if (vec.empty())
            dist += prev * 2;
    }

    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K >> S;

    vector<pair<int, int>> left, right;
    for (int n = 0; n < N; ++n) {
        int a, b;
        cin >> a >> b;

        if (a < S)
            left.emplace_back(a, b);
        else
            right.emplace_back(a, b);
    }

    sort(left.begin(), left.end(), greater<pair<int, int>>());
    sort(right.begin(), right.end(), less<pair<int, int>>());

    cout << get_dist(left) + get_dist(right) << '\n';
    return 0;
}