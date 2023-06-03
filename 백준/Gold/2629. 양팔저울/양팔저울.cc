#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <unordered_set>

using namespace std;

int N, M, Arr[31];
bool DP[40001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> Arr[i];

    DP[0] = true;
    for (int i = 1; i <= N; ++i) {
        for (int j = 40000; j >= 0; --j) {
            if (DP[j])
                DP[j + Arr[i]] = true;
        }

        for (int j = 0; j < 40000; ++j) {
            if (DP[j])
                DP[::abs(j - Arr[i])] = true;
        }
    }

    cin >> M;

    int num;
    for (int i = 0; i < M; ++i) {
        cin >> num;

        if (DP[num])
            cout << 'Y' << ' ';
        else
            cout << 'N' << ' ';
    }
    return 0;
}