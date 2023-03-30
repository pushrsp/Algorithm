#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321
#define MAX 11

using namespace std;

int N, M, Dist[MAX][MAX];
int Ret = INF;
bool Visited[MAX];

void go(int curr, int count, int sum) {
    if (count == N) {
        Ret = min(Ret, sum);
        return;
    }

    for (int i = 0; i < N; ++i) {
        if (Visited[i])
            continue;

        Visited[i] = true;
        go(i, count + 1, sum + Dist[curr][i]);
        Visited[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> Dist[i][j];
        }
    }

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                Dist[i][j] = min(Dist[i][j], Dist[i][k] + Dist[k][j]);
            }
        }
    }

    Visited[M] = true;
    go(M, 1, 0);
    cout << Ret << '\n';
    return 0;
}