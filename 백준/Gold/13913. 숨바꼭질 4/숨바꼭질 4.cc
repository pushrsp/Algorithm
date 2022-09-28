#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, K;
int Dist[100001], Parent[100001];

int main() {
    cin >> N >> K;

    queue<int> q;

    q.push(N);
    Dist[N] = 1;
    Parent[N] = N;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int next: {now + 1, now - 1, now * 2}) {
            if (0 <= next && next <= 100000) {
                if (!Dist[next]) {
                    q.push(next);
                    Dist[next] = Dist[now] + 1;
                    if (Parent[next] == 0)
                        Parent[next] = now;
                }
            }
        }
    }

    vector<int> path;
    path.push_back(K);

    int pos = K;
    while (Parent[pos] != pos) {
        path.push_back(Parent[pos]);
        pos = Parent[pos];
    }
    reverse(path.begin(), path.end());

    cout << Dist[K] - 1 << '\n';
    for (int p: path)
        cout << p << " ";

    return 0;
}