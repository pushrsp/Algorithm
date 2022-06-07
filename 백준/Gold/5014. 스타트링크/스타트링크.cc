#include <iostream>
#include <queue>

using namespace std;

bool visited[1000002];
int dist[1000002];
int F, S, G, U, D;

void BFS(int n) {
    queue<int> q;
    q.push(n);
    visited[n] = true;

    while (!q.empty()) {
        n = q.front();
        q.pop();

        if (n == G) {
            cout << dist[G] << endl;
            return;
        }

        for (int i = 0; i < 2; ++i) {
            int next;
            switch (i) {
                case 0:
                    next = n + U;
                    break;
                case 1:
                    next = n - D;
                    break;
            }

            if (next < 1 || next > F)
                continue;
            if (visited[next])
                continue;

            q.push(next);
            visited[next] = true;
            dist[next] = dist[n] + 1;
        }
    }

    cout << "use the stairs" << endl;
}

int main() {
    cin >> F >> S >> G >> U >> D;
    BFS(S);
    return 0;
}