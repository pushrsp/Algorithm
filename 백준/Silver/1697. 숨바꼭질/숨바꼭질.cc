#include <iostream>
#include <map>
#include <queue>

using namespace std;

int start, dest;
bool visited[100001];
int dist[100001];
int delta[3] = {1, 2, 3}; //빼기, 더하기, 곱하기

void BFS() {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int n = q.front();
        q.pop();

        if (n == dest)
            break;

        for (int i = 0; i < 3; ++i) {
            int next;
            switch (delta[i]) {
                case 1:
                    next = n - 1;
                    break;
                case 2:
                    next = n + 1;
                    break;
                case 3:
                    next = n * 2;
                    break;
            }

            if (next < 0 || next > 100000)
                continue;
            if (visited[next])
                continue;

            q.push(next);
            visited[next] = true;
            dist[next] = dist[n] + 1;
        }
    }

    cout << dist[dest] << endl;
}

int main() {
    cin >> start >> dest;

    BFS();
    return 0;
}