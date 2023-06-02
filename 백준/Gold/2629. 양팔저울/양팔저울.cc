#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_set>

using namespace std;

int N, M, Arr[31];
bool Visited[31][16000];

void go(int n, int sum) {
    if (n == N + 1)
        return;
    if (Visited[n][sum])
        return;

    Visited[n][sum] = true;

    go(n + 1, sum + Arr[n]);
    go(n + 1, sum);
    go(n + 1, ::abs(sum - Arr[n]));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> Arr[i];

    cin >> M;

    go(0, 0);

    int num;
    for (int i = 0; i < M; ++i) {
        cin >> num;

        if (num > 15000) {
            cout << 'N' << ' ';
            continue;
        }

        if (Visited[N][num])
            cout << 'Y' << ' ';
        else
            cout << 'N' << ' ';
    }
    return 0;
}