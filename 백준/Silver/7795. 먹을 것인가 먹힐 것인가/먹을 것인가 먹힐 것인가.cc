#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int T, N, M, A[20001], B[20001];

int get_cnt(int cmp) {
    int left = 0, right = M - 1, mid;
    while (left <= right) {
        mid = (left + right) / 2;

        if (cmp <= B[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }

    return left;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> N >> M;

        for (int n = 0; n < N; ++n)
            cin >> A[n];
        for (int m = 0; m < M; ++m)
            cin >> B[m];

        sort(B, B + M);
        int cnt = 0;
        for (int i = 0; i < N; ++i)
            cnt += get_cnt(A[i]);

        cout << cnt << '\n';
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
    }
    return 0;
}