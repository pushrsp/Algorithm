#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int N, M, K;
int a[1001], b[1001], psum_a[2002], psum_b[2002];
map<int, int> aCnt, bCnt;

void make(int n, int psum[], map<int, int> &_map) {
    for (int interval = 1; interval <= n; interval++) {
        for (int start = interval; start <= n + interval - 1; start++) {
            int idx = start - interval;
            int sum = psum[start] - psum[idx];
            _map[sum]++;

            if (interval == n)
                break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K;
    cin >> M >> N;

    for (int i = 1; i <= M; ++i) {
        cin >> a[i];
        psum_a[i] = psum_a[i - 1] + a[i];
    }

    for (int i = M + 1; i <= M * 2; ++i)
        psum_a[i] = psum_a[i - 1] + a[i - M];

    for (int i = 1; i <= N; ++i) {
        cin >> b[i];
        psum_b[i] = psum_b[i - 1] + b[i];
    }

    for (int i = N + 1; i <= N * 2; ++i)
        psum_b[i] = psum_b[i - 1] + b[i - N];

    make(M, psum_a, aCnt);
    make(N, psum_b, bCnt);

    int sum = 0;
    for (int i = 1; i < K; i++)
        sum += aCnt[K - i] * bCnt[i];

    sum += aCnt[K];
    sum += bCnt[K];

    cout << sum << "\n";

    return 0;
}