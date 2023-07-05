#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, A[1001], B[1001], C[1001];

int go(int left, int right, int oper) {
    if (left > right)
        return 0;

    int ret = 0;
    if (left == right) {
        ret = ::abs(A[left] - B[left]);
        A[left] = B[left];
        return ret;
    }

    int index = left;
    for (int i = left; i <= right; ++i) {
        if (::abs(A[i] - B[i]) < ::abs(A[index] - B[index]))
            index = i;
    }

    int offset = ::abs(A[index] - B[index]);
    for (int i = left; i <= right; ++i) {
        if (oper == 1)
            A[i] += offset;
        else
            A[i] -= offset;
    }

    ret += offset + go(left, index - 1, oper) + go(index + 1, right, oper);

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int n = 1; n <= N; ++n)
        cin >> A[n];
    for (int n = 1; n <= N; ++n) {
        cin >> B[n];

        if (B[n] - A[n] > 0) // +
            C[n] = 1;
        else if (B[n] - A[n] == 0)
            C[n] = 0;
        else // -
            C[n] = -1;
    }

    vector<pair<int, int>> vec;
    int prev = 1;
    for (int n = 2; n <= N; ++n) {
        if (C[prev] != C[n]) {
            vec.emplace_back(prev, n - 1);
            prev = n;
        }

        if (n == N)
            vec.emplace_back(prev, N);
    }

    int ret = 0;
    for (auto &p: vec)
        ret += go(p.first, p.second, C[p.first]);

    cout << ret << '\n';

    return 0;
}