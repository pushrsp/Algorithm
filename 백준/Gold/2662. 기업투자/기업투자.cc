#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M, Arr[301][21], DP[301][21], Trace[301][21];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    int c;
    for (int n = 1; n <= N; ++n) {
        cin >> c;

        for (int m = 1; m <= M; ++m)
            cin >> Arr[n][m];
    }

    for (int n = 1; n <= N; ++n) { //돈
        for (int m = 1; m <= M; ++m) { //기업
            for (int k = 0; k <= n; ++k) {
                if (Arr[k][m] + DP[n - k][m - 1] > DP[n][m]) {
                    DP[n][m] = Arr[k][m] + DP[n - k][m - 1];
                    Trace[n][m] = k;
                }
            }
        }
    }

    cout << DP[N][M] << '\n';

    vector<int> answer;
    for (int m = M; m >= 1; --m) {
        answer.push_back(Trace[N][m]);
        N -= Trace[N][m];
    }

    for (int i = answer.size() - 1; i >= 0; --i)
        cout << answer[i] << ' ';

    return 0;
}