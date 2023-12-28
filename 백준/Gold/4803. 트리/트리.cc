#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
vector<int> Adj[501];
bool Visited[501];

void go(int curr, int &v, int &e) {
    Visited[curr] = true;

    for (auto &next: Adj[curr]) {
        e++;

        if (Visited[next])
            continue;

        v++;
        go(next, v, e);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    while (true) {
        cin >> N >> M;

        if (N == 0 && M == 0)
            break;

        ::memset(Visited, false, sizeof(Visited));

        for (int n = 0; n <= N; ++n)
            Adj[n].clear();

        int a, b;
        for (int m = 0; m < M; ++m) {
            cin >> a >> b;

            Adj[a].push_back(b);
            Adj[b].push_back(a);
        }

        int count = 0;
        for (int n = 1; n <= N; ++n) {
            if (Visited[n])
                continue;

            int v = 1, e = 0;
            go(n, v, e);

            /*
             * 트리의 조건
             * n개의 정점이 있으면 간선의 개수는 n-1이다.
             */

            if ((v - 1) * 2 == e)
                count++;
        }

        cout << "Case " << t << ": ";

        if (count == 0)
            cout << "No trees." << '\n';
        else if (count == 1)
            cout << "There is one tree." << '\n';
        else
            cout << "A forest of " << count << " trees." << '\n';

        t++;
    }
    return 0;
}