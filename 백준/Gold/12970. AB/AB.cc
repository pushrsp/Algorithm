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

    int a = 0, b = N, prev = 0;
    while (true) {
        int sum = a * b;
        if (sum < prev) {
            cout << -1 << '\n';
            return 0;
        }

        if (sum >= K) {
            for (int i = 0; i < a - 1; ++i)
                s[i] = 'A';

            int c = (a - 1) * b;
            int r = K - c;
            s[(N - 1) - r] = 'A';
            
            break;
        }

        prev = sum;
        a++, b--;
    }

    cout << s << '\n';

    return 0;
}