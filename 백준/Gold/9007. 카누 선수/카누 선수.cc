#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int T, K, N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> K >> N;

        int t1[1001], t2[1001];

        for (int n = 0; n < N; ++n)
            cin >> t1[n];
        for (int n = 0; n < N; ++n)
            cin >> t2[n];

        vector<int> s1;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j)
                s1.push_back(t1[i] + t2[j]);
        }

        for (int n = 0; n < N; ++n)
            cin >> t1[n];
        for (int n = 0; n < N; ++n)
            cin >> t2[n];

        vector<int> s2;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j)
                s2.push_back(t1[i] + t2[j]);
        }

        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        int ret = INT32_MAX, offset = INT32_MAX;
        for (auto &sum: s1) {
            int mid = K - sum;
            int i = lower_bound(s2.begin(), s2.end(), mid) - s2.begin();

            if (i == N * N)
                i--;

            int total = sum + s2[i];
            int gap = abs(K - total);

            if (gap < offset) {
                offset = gap;
                ret = total;
            } else if (gap == offset) {
                offset = gap;
                ret = min(ret, total);
            }

            if (i != 0) {
                total = sum + s2[i - 1];
                gap = abs(K - total);

                if (gap < offset) {
                    offset = gap;
                    ret = total;
                } else if (gap == offset) {
                    offset = gap;
                    ret = min(ret, total);
                }
            }
        }

        cout << ret << '\n';
    }
    return 0;
}