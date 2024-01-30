#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

#define ll long long

using namespace std;

int N;
ll X, A[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> X;

    for (int n = 0; n < N; ++n)
        cin >> A[n];

    ll ret;

    if (abs(A[0] - A[1]) < X) {
        if (A[0] > A[1])
            ret = A[1] + X - A[0];
        else
            ret = A[0] + X - A[1];
    } else {
        ret = 0;
    }

    if (abs(A[N - 2] - A[N - 1]) < X) {
        if (A[N - 2] > A[N - 1])
            ret = min(ret, A[N - 1] + X - A[N - 2]);
        else
            ret = min(ret, A[N - 2] + X - A[N - 1]);
    } else {
        ret = 0;
    }

    for (int n = 1; n < N - 1; ++n) {
        ll left = A[n - 1], mid = A[n], right = A[n + 1];

        if (abs(mid - left) < X) {
            if (A[n] > A[n - 1])
                mid = A[n - 1] + X;
            else
                left = A[n] + X;
        }

        if (abs(mid - right) < X) {
            if (mid > right) {
                mid = right + X;

                if (abs(mid - left) < X) {
                    if (mid > left)
                        mid = left + X;
                    else
                        left = mid + X;
                }
            } else {
                right = mid + X;
            }
        }

        ret = min(ret, abs(left - A[n - 1]) + abs(mid - A[n]) + abs(right - A[n + 1]));
    }

    cout << ret << '\n';

    return 0;
}