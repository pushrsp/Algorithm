#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

#define ll long long

using namespace std;

int N, Q, A[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    int s, e;
    for (int n = 0; n < N; ++n) {
        cin >> s >> e;

        A[s] += 1, A[e + 1] -= 1;
    }

    for (int i = 1; i < 1000001; ++i)
        A[i] += A[i - 1];

    cin >> Q;

    int t;
    for (int q = 0; q < Q; ++q) {
        cin >> t;

        cout << A[t] << '\n';
    }

    return 0;
}