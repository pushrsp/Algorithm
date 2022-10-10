#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int A[200001], B[200001], N, M;

bool is_valid(int cmp) {
    int left = 0, right = M - 1, mid;
    while (left <= right) {
        mid = (left + right) / 2;

        if (B[mid] < cmp) {
            left = mid + 1;
        } else if (B[mid] > cmp) {
            right = mid - 1;
        } else {
            break;
        }
    }

    return B[mid] == cmp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int n = 0; n < N; ++n)
        cin >> A[n];
    for (int m = 0; m < M; ++m)
        cin >> B[m];

    sort(A, A + N);
    sort(B, B + M);

    int cnt = 0;
    for (int n = 0; n < N; ++n) {
        if (is_valid(A[n]))
            cnt++;
    }

    cout << (N - cnt) + (M - cnt) << '\n';
    return 0;
}