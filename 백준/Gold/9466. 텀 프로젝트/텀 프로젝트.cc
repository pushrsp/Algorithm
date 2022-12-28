#include <iostream>
#include <vector>

#define MAX 100001

using namespace std;

int T, N, Adj[MAX], Visited[MAX], Temp, Ret;
bool Finished[MAX];

void Clear() {
    for (int i = 1; i <= N; ++i)
        Visited[i] = false, Finished[i] = false;

    Temp = 0, Ret = 0;
}

void go(int node) {
    Visited[node] = Temp++;

    if (!Visited[Adj[node]])
        go(Adj[node]);
    else if (!Finished[Adj[node]])
        Ret += Visited[node] - Visited[Adj[node]] + 1;

    Finished[node] = true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> N;

        for (int i = 1; i <= N; ++i)
            cin >> Adj[i];

        for (int i = 1; i <= N; ++i) {
            if (!Finished[i])
                go(i);
        }

        cout << N - Ret << '\n';
        Clear();
    }
    return 0;
}