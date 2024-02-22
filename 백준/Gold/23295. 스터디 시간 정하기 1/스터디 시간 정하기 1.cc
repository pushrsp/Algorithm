#include <cstring>
#include <vector>
#include <deque>
#include <iostream>
#include <cmath>
#include <map>

#define ll long long

using namespace std;

int N, T, S, E, K;
ll Sum[100001], A[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> T;

    for (int n = 0; n < N; ++n) {
        cin >> K;

        for (int k = 0; k < K; ++k) {
            cin >> S >> E;
            A[S]++, A[E]--;
        }
    }

    for (int i = 1; i <= 100000; ++i)
        A[i] += A[i - 1];

    Sum[0] = A[0];
    for (int i = 1; i <= 100000; ++i)
        Sum[i] += Sum[i - 1] + A[i];

    ll ans = Sum[T - 1], s = 0, e = T;
    for (int i = 1; i <= 100000 - T; ++i) {
        if (Sum[i + T - 1] - Sum[i - 1] > ans)
            s = i, e = i + T;

        ans = max(ans, Sum[i + T - 1] - Sum[i - 1]);
    }

    cout << s << ' ' << e << '\n';

    return 0;
}