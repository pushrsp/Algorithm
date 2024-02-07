#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

#define ll long long

using namespace std;

int N, A[5000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int n = 0; n < N; ++n)
        cin >> A[n];

    int ret = 0;
    for (int n = 0; n < N; ++n) {
        int j = n + 1, wall = A[n];
        for (; j < N; j++) {
            if (A[j] >= wall)
                break;
            else
                wall = A[j];
        }

        n = j - 1;

        ret += 1;
    }

    cout << ret << '\n';

    return 0;
}