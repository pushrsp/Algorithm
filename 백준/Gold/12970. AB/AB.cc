#include <iostream>
#include <queue>
#include <algorithm>

#define INF 987654321

using namespace std;

int N, K;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;

    string s;
    for (int n = 0; n < N; ++n)
        s.push_back('B');

    if (K == 0) {
        cout << s << '\n';
        return 0;
    }

    int a = 1, b = N - 1, prev = 0;
    while (true) {
        int sum = a * b;
        if (sum < prev) {
            cout << -1 << '\n';
            return 0;
        }

        if (sum >= K) {
            vector<int> cnt(b + 1);
            for (int i = 0; i < a; ++i) {
                int mn = min(b, K);
                cnt[b - mn]++;
                K -= mn;
            }

            for (int i = 0; i <= b; ++i) {
                for (int j = 0; j < cnt[i]; ++j)
                    cout << 'A';
                if (i < b)
                    cout << 'B';
            }

            cout << '\n';
            return 0;
        }

        prev = sum;
        a++, b--;
    }

    return 0;
}